/*
Scalpel - Source Code Analysis, Libre and PortablE Library
Copyright © 2008, 2009  Florian Goujeon

This file is part of Scalpel.

Scalpel is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Scalpel is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Scalpel.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "syntax_analyzer.hpp"

#include <iostream>
#include <stdexcept>
#include <boost/spirit/tree/parse_tree.hpp>
#include "../util/raii_affector.hpp"
#include "detail/syntax_analysis/parse_tree_to_syntax_tree/conversion_functions.hpp"
#include "detail/syntax_analysis/parse_tree_to_syntax_tree/basic_functions.hpp"
#include "detail/syntax_analysis/source_code_completion.hpp"
#include "detail/semantic_analysis/name_lookup.hpp"
#include "semantic_graph.hpp"

using namespace boost::spirit;
using namespace scalpel::cpp::syntax_nodes;
using namespace scalpel::util;
using namespace scalpel::cpp::detail::syntax_analysis;
using namespace scalpel::cpp::detail::semantic_analysis;

namespace scalpel { namespace cpp
{

syntax_analyzer::type_name_parser::type_name_parser(syntax_analyzer& a):
    syntax_analyzer_(a)
{
}

std::ptrdiff_t
syntax_analyzer::type_name_parser::operator()(const scanner_t& scan) const
{
    return syntax_analyzer_.parse_type_name(scan);
}


syntax_analyzer::syntax_analyzer():
    type_name_parser_(*this),
	grammar_(type_name_parser_)
{
}

syntax_tree
syntax_analyzer::operator()(const std::string& input)
{
    input_ = &input;
    highest_parsing_progress_ = 0;
    performing_semantic_analysis_ = false;
	type_name_map_.clear();

    return analyze(input);
}

syntax_tree
syntax_analyzer::analyze(const std::string& input)
{
	currently_analyzed_partial_input_ = &input;

    //parse the input with the C++ grammar
    boost::spirit::tree_parse_info<> info = boost::spirit::pt_parse
    (
        input.c_str(),
        grammar_.get_start_rule()
    );

	currently_analyzed_partial_input_ = input_;

    //throw an exception if parsing fails
    if(!info.full)
    {
        std::ostringstream failure_message;
        failure_message << "Parsing stopped at:\n***\n" << info.stop << "\n***";
        throw std::runtime_error(failure_message.str().c_str());
    }

    //convert spirit's parse tree to syntax tree and return the result
	return parse_tree_to_syntax_tree::convert_translation_unit
	(
		parse_tree_to_syntax_tree::get_only_child_node
		(
			*info.trees.begin()
		)
	);
}

/**
 * This function is called when the grammar has to check whether a name
 * represents a type or not.
 */
std::ptrdiff_t
syntax_analyzer::parse_type_name(const scanner_t& scan)
{
    unsigned int parsing_progress = scan.first - &*(currently_analyzed_partial_input_->begin());

	//
	//Get the name to be checked.
	//
	std::string name;
	char ch = *scan;
	while
	(
		!scan.at_end() &&
		(
			(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch == '_') ||
			(ch >= '0' && ch <= '9')
		)
	)
	{
		name += ch;
		++scan;
		ch = *scan;
	}


	//if we already checked that name at the same progress point...
	if
	(
		highest_parsing_progress_ != 0 &&
		highest_parsing_progress_ >= parsing_progress
	)
	{
		//... just return the result we stored
		std::map<unsigned int, bool>::const_iterator is_a_type_it = type_name_map_.find(parsing_progress);
		if(is_a_type_it == type_name_map_.end()) //assert that a result is found
		{
		//	print_type_name_map_();
		//	assert(false);
		}
		else
		{
			if(is_a_type_it->second)
				return name.size(); //successful match
			else
				return -1;
		}
	}
	highest_parsing_progress_ = parsing_progress;

	//if we're not already performing a semantic analysis (avoid recursive call)
	if(!performing_semantic_analysis_)
	{
		raii_affector<bool, true, false> raii_aff(performing_semantic_analysis_);

		//
		//Create a new string from the beginning of the input to the current
		//location of the scanner.
		//
		assert(currently_analyzed_partial_input_);
		std::string partial_input(&*(currently_analyzed_partial_input_->begin()), scan.first);

		std::cout << "\nTry to determine whether '" << name << "' is a type name...\n";
		std::cout << "Fragment of input succesfully parsed:\n";
		std::cout << "***\n" << partial_input << "\n***\n";

		//
		//Complete the scanned source code (partial_input) in order to have
		//a syntactically correct input to analyze.
		//
		unsigned int closed_scope_count = source_code_completion::complete(partial_input);
		std::cout << "Completed input:\n";
		std::cout << "***\n" << partial_input << "\n***\n";

		//
		//Analyze the source code's syntax
		//
		std::cout << "Syntax analysis:\n";
		syntax_tree syntax_nodes = analyze(partial_input);

		//
		//Analyze the source code's semantic
		//
		std::cout << "Semantic analysis:\n";
		semantic_graph graph = semantic_analyzer_(syntax_nodes);

		//
		//Get the scope from where to find the given type name.
		//
		auto lastly_closed_scopes = graph.lastly_closed_scope_reverse_iterator();
		auto lastly_closed_scope_it = lastly_closed_scopes.begin();
		assert(closed_scope_count + 1 <= static_cast<unsigned int>(lastly_closed_scopes.size())); //+1 for global namespace
		for(unsigned int i = 0; i < closed_scope_count; ++i)
		{
			++lastly_closed_scope_it;
		}
		const semantic_entities::scope& scope = *lastly_closed_scope_it;

		//
		//Check whether the name is really a type name.
		//
		const semantic_entities::named_entity* const item = name_lookup::find_unqualified_name(scope, name);
		if(item && item->is_a_type())
		{
			std::cout << "'" << name << "' is a type name.\n";
			type_name_map_.insert(std::make_pair<unsigned int, bool>(parsing_progress, true)); //store the result
			return name.size(); //successful match
		}
		else
		{
			std::cout << "'" << name << "' isn't a type name.\n";
			type_name_map_.insert(std::make_pair<unsigned int, bool>(parsing_progress, false)); //store the result
		}
    }

    return -1;
}

void
syntax_analyzer::print_type_name_map_()
{
	for
	(
		std::map<unsigned int, bool>::iterator i = type_name_map_.begin();
		i != type_name_map_.end();
		++i
	)
	{
		std::cout << "type_name_map[" << i->first << "] = " << i->second << "\n";
	}
}

}} //namespace scalpel::cpp