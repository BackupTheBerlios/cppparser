/*
Scalpel - Source Code Analysis, Libre and PortablE Library
Copyright © 2008 - 2010  Florian Goujeon

This file is part of Scalpel.

Scalpel is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Scalpel is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Scalpel.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCALPEL_CPP_SYNTAX_NODES_FLOATING_LITERAL_HPP
#define SCALPEL_CPP_SYNTAX_NODES_FLOATING_LITERAL_HPP

#include "leaf_node.hpp"
#include <string>

namespace scalpel { namespace cpp { namespace syntax_nodes
{

struct floating_literal: public leaf_node
{
	floating_literal(std::string&& value):
		leaf_node(value)
	{
	}

	floating_literal(const floating_literal& o):
		leaf_node(o)
	{
	}

	floating_literal(floating_literal&& o):
		leaf_node(o)
	{
	}
};

}}} //namespace scalpel::cpp::syntax_nodes

#endif
