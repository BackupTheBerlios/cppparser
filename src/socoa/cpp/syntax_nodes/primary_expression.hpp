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

#ifndef SOCOA_CPP_SYNTAX_NODES_PRIMARY_EXPRESSION_HPP
#define SOCOA_CPP_SYNTAX_NODES_PRIMARY_EXPRESSION_HPP

#include "alternative_node.hpp"
#include "simple_text_node.hpp"
#include "literal.hpp"
#include "round_bracketed_expression.hpp"
#include "id_expression.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

typedef
	alternative_node
	<
		simple_text_node<util::extern_strings::this_>,
		literal,
		round_bracketed_expression,
		id_expression
	>
	primary_expression
;

}}} //namespace socoa::cpp::syntax_nodes

#endif
