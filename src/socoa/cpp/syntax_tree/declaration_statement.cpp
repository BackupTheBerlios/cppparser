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

#include "declaration_statement.hpp"

namespace socoa { namespace cpp { namespace syntax_tree
{

declaration_statement::declaration_statement
(
)
{
	update_node_list();
}

declaration_statement::declaration_statement(const declaration_statement& o):
	composite_node()
{
	update_node_list();
}

declaration_statement::declaration_statement(declaration_statement&& o):
	composite_node()
{
	update_node_list();
}

const declaration_statement&
declaration_statement::operator=(const declaration_statement& o)
{
	update_node_list();

	return *this;
}

void
declaration_statement::update_node_list()
{
	clear();
}

}}} //namespace socoa::cpp::syntax_tree

