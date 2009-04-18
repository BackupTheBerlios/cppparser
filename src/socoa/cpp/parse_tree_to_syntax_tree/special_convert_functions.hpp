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

#ifndef SOCOA_CPP_PARSE_TREE_TO_SYNTAX_TREE_SPECIAL_CONVERT_FUNCTIONS_HPP
#define SOCOA_CPP_PARSE_TREE_TO_SYNTAX_TREE_SPECIAL_CONVERT_FUNCTIONS_HPP

#include <string>
#include <vector>
#include "../../util/string_enumeration.hpp"
#include "typedefs.hpp"
#include "convert_function_callers.hpp"
#include "node_converter.hpp"

namespace socoa { namespace cpp { namespace parse_tree_to_syntax_tree
{

template<class T>
T
convert_string_enumeration(const tree_node_t& node)
{
	return T
	(
		get_only_child_value(node)
	);
}

template<class ContainerT>
ContainerT
convert_sequence(const tree_node_t& node)
{
	ContainerT seq;

	if(ContainerT::separator_node.raw_code() == syntax_tree::empty.raw_code())
	{
		boost::optional<syntax_tree::space> space_node;
		for(tree_node_iterator_t i = node.children.begin(); i != node.children.end(); ++i) //for each child node
		{
			const tree_node_t& child_node = *i;
			const std::string child_value = get_value(child_node);

			if(child_node.value.id() == id_t::SPACE)
			{
				space_node = convert_node<syntax_tree::space, id_t::SPACE>(child_node);
			}
			else
			{
				typename ContainerT::item item
				(
					space_node,
					boost::optional<syntax_tree::space>(),
					convert_function_caller_from_type<typename ContainerT::type>::convert(child_node)
				);
				seq.push_back(item);

				//clear space node
				space_node = boost::optional<syntax_tree::space>();
			}
		}
	}
	else
	{
		boost::optional<syntax_tree::space> space_node1;
		boost::optional<syntax_tree::space> space_node2;
		bool will_read_space_node2 = false;
		for(tree_node_iterator_t i = node.children.begin(); i != node.children.end(); ++i) //for each child node
		{
			const tree_node_t& child_node = *i;
			const std::string child_value = get_value(child_node);

			if(child_value == ContainerT::separator_node.raw_code()) //if the node is a separator
			{
				will_read_space_node2 = true;
			}
			else if(child_node.value.id() == id_t::SPACE)
			{
				if(!will_read_space_node2)
				{
					space_node1 = convert_node<syntax_tree::space, id_t::SPACE>(child_node);
					will_read_space_node2 = true;
				}
				else
				{
					space_node2 = convert_node<syntax_tree::space, id_t::SPACE>(child_node);
					will_read_space_node2 = false;
				}
			}
			else
			{
				typename ContainerT::item item
				(
					space_node1,
					space_node2,
					convert_function_caller_from_type<typename ContainerT::type>::convert(child_node)
				);
				seq.push_back(item);

				will_read_space_node2 = false;
			}
		}
	}

	return seq;
}

}}} //namespace socoa::cpp::parse_tree_to_syntax_tree

#endif
