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

#include "bracketed_expression_list.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

bracketed_expression_list::bracketed_expression_list
(
)
{
	update_node_list();
}

bracketed_expression_list::bracketed_expression_list(const bracketed_expression_list& o):
	composite_node()
{
	update_node_list();
}

bracketed_expression_list::bracketed_expression_list(bracketed_expression_list&& o):
	composite_node()
{
	update_node_list();
}

const bracketed_expression_list&
bracketed_expression_list::operator=(const bracketed_expression_list& o)
{
	update_node_list();

	return *this;
}

void
bracketed_expression_list::update_node_list()
{
	clear();
}

}}} //namespace socoa::cpp::syntax_nodes

