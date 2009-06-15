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

#include "explicit_instantiation.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

explicit_instantiation::explicit_instantiation
(
	optional_node<simple_text_node<str::extern_>>&& o0,
	optional_node<space>&& o1,
	simple_text_node<str::template_>&& o2,
	optional_node<space>&& o3,
	declaration&& o4
):
	impl_(o0, o1, o2, o3, o4)
{
	add(impl_);
}

explicit_instantiation::explicit_instantiation
(
	head_node_t&& head,
	tail_sequence_node_t&& tail
):
	impl_(head, tail)
{
	add(impl_);
}

explicit_instantiation::explicit_instantiation(const explicit_instantiation& o):
	composite_node(),
	impl_(o.impl_)
{
	add(impl_);
}

explicit_instantiation::explicit_instantiation(explicit_instantiation&& o):
	composite_node(),
	impl_(std::move(o.impl_))
{
	add(impl_);
}

const explicit_instantiation&
explicit_instantiation::operator=(const explicit_instantiation& o)
{
	impl_ = o.impl_;
	return *this;
}

}}} //namespace scalpel::cpp::syntax_nodes
