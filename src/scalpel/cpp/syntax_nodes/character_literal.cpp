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

#include "character_literal.hpp"

#include "common_nodes.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

character_literal::character_literal
(
	bool wide,
	std::string&& value
):
	wide_(wide),
	value_(value)
{
	update_node_list();
}

character_literal::character_literal(const character_literal& o):
	composite_node(),
	wide_(o.wide_),
	value_(o.value_)
{
	update_node_list();
}

character_literal::character_literal(character_literal&& o):
	composite_node(),
	wide_(std::move(o.wide_)),
	value_(std::move(o.value_))
{
	update_node_list();
}

const character_literal&
character_literal::operator=(const character_literal& o)
{
	wide_ = o.wide_;
	value_ = o.value_;

	update_node_list();

	return *this;
}

void
character_literal::update_node_list()
{
	clear();

	if(wide_) add(common_nodes::capital_l);
	add(common_nodes::single_quote);
	add(value_);
	add(common_nodes::single_quote);
}

}}} //namespace scalpel::cpp::syntax_nodes
