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

#include "declarator.hpp"

#include "direct_declarator.hpp"

namespace socoa { namespace cpp { namespace syntax_tree
{

declarator::declarator
(
    std::vector<ptr_operator>&& ptr_operators,
    direct_declarator&& a_direct_declarator
):
    ptr_operators_(std::move(ptr_operators)),
    direct_declarator_(std::make_shared<direct_declarator>(std::move(a_direct_declarator)))
{
	for(auto i = ptr_operators_.begin(); i != ptr_operators_.end(); ++i)
		add(*i);

	add(*direct_declarator_);
}

declarator::declarator(declarator&& o):
    ptr_operators_(std::move(o.ptr_operators_)),
    direct_declarator_(std::move(o.direct_declarator_))
{
}

}}} //namespace socoa::cpp::syntax_tree
