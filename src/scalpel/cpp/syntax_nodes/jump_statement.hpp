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

#ifndef SCALPEL_CPP_SYNTAX_NODES_JUMP_STATEMENT_HPP
#define SCALPEL_CPP_SYNTAX_NODES_JUMP_STATEMENT_HPP

#include "break_statement.hpp"
#include "continue_statement.hpp"
#include "return_statement.hpp"
#include "goto_statement.hpp"
#include "common.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

typedef
	alternative_node
	<
		break_statement,
		continue_statement,
		return_statement,
		goto_statement
	>
	jump_statement
;

}}} //namespace scalpel::cpp::syntax_nodes

#endif
