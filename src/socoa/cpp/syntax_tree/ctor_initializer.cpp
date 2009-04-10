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

#include "ctor_initializer.hpp"

namespace socoa { namespace cpp { namespace syntax_tree
{

ctor_initializer::ctor_initializer
(
    mem_initializer_list&& a_mem_initializer_list
):
    mem_initializer_list_(a_mem_initializer_list)
{
	update_node_list();
}

ctor_initializer::ctor_initializer(const ctor_initializer& o):
	composite_node(),
    mem_initializer_list_(o.mem_initializer_list_)
{
	update_node_list();
}

ctor_initializer::ctor_initializer(ctor_initializer&& o):
    mem_initializer_list_(std::move(o.mem_initializer_list_))
{
	update_node_list();
}

const ctor_initializer&
ctor_initializer::operator=(const ctor_initializer& o)
{
    mem_initializer_list_ = std::move(o.mem_initializer_list_);
	update_node_list();

	return *this;
}

void
ctor_initializer::update_node_list()
{
	clear();
	add(mem_initializer_list_);
}

}}} //namespace socoa::cpp::syntax_tree
