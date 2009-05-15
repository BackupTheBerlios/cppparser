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

#ifndef SCALPEL_CPP_SYNTAX_NODES_PARAMETER_DECLARATION_LIST_HPP
#define SCALPEL_CPP_SYNTAX_NODES_PARAMETER_DECLARATION_LIST_HPP

#include "../../util/extern_strings.hpp"
#include "sequence_node.hpp"
#include "parameter_declaration.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

typedef
	sequence_node<parameter_declaration, common_nodes::comma>
   	parameter_declaration_list
;

}}} //namespace scalpel::cpp::syntax_nodes

#endif