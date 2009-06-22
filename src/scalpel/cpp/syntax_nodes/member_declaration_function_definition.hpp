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

#ifndef SCALPEL_CPP_SYNTAX_NODES_MEMBER_DECLARATION_FUNCTION_DEFINITION_HPP
#define SCALPEL_CPP_SYNTAX_NODES_MEMBER_DECLARATION_FUNCTION_DEFINITION_HPP

#include "common.hpp"
#include "function_definition.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

/**
member_declaration_function_definition
	= function_definition >> !(!s >> ch_p(';'))
;
*/
typedef
	sequence_node
	<
		function_definition,
		optional_node<space>,
		optional_node<predefined_text_node<str::semicolon>>
	>
	member_declaration_function_definition
;

}}} //namespace scalpel::cpp::syntax_nodes

#endif
