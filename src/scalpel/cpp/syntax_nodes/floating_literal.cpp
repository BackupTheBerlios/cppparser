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

#include "floating_literal.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

floating_literal::floating_literal
(
	std::string&& value
):
	value_(value)
{
	update_node_list();
}

floating_literal::floating_literal(const floating_literal& o):
	composite_node(),
	value_(o.value_)
{
	update_node_list();
}

floating_literal::floating_literal(floating_literal&& o):
	composite_node(),
	value_(std::move(o.value_))
{
	update_node_list();
}

const floating_literal&
floating_literal::operator=(const floating_literal& o)
{
	value_ = o.value_;

	update_node_list();

	return *this;
}

void
floating_literal::update_node_list()
{
	clear();
	add(value_);
}

}}} //namespace scalpel::cpp::syntax_nodes
