/*
Socoa - Source Code Analysis Library
Copyright © 2008, 2009  Florian Goujeon

This file is part of Socoa.

Socoa is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Socoa is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Socoa.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "syntax_analyzer.h"

#include <iostream>
#include <boost/spirit/tree/parse_tree.hpp>
#include "parse_tree_to_syntax_tree.h"
#include "source_code_completion.h"

using namespace boost::spirit;
using namespace socoa::cpp::syntax_tree;
using namespace socoa::util;

namespace socoa { namespace cpp
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

std::shared_ptr<syntax_tree_t>
syntax_analyzer::operator()(const std::string& input)
{
    input_ = &input;

    return analyze(input);
}

std::shared_ptr<syntax_tree_t>
syntax_analyzer::analyze(const std::string& input)
{
    //parse the input with the C++ grammar
    boost::spirit::tree_parse_info<> info = boost::spirit::pt_parse
    (
        input.c_str(),
        grammar_.get_start_rule(),
        boost::spirit::space_p
    );

    //throw an exception if parsing fails
    if(!info.full)
    {
        std::ostringstream failure_message;
        failure_message << "Parsing stopped at:\n***\n" << info.stop << "\n***";
        throw std::runtime_error(failure_message.str().c_str());
    }

    //convert spirit's parse tree to syntax tree
    return parse_tree_to_syntax_tree::convert_file(*info.trees.begin());
}

std::ptrdiff_t
syntax_analyzer::parse_type_name(const scanner_t& scan)
{
    assert(input_);

    std::cout << "Parsing type name...\n";

    /*
    Create a new string from the beginning of the input to the current
    location of the scanner.
    */
    std::string partial_input(&*(input_->begin()), scan.first);
    std::cout << "Fragment of input succesfully parsed:\n";
    std::cout << "***\n" << partial_input << "\n***\n";

    source_code_completion::complete(partial_input);

    std::cout << "\n";
    return -1;
}

}} //namespace socoa::cpp
