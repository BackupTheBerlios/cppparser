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

#include "array.hpp"

namespace scalpel { namespace cpp { namespace semantic_entities
{

array::array(const unsigned int size, std::shared_ptr<const type> decorated_type):
	size_(size),
	decorated_type_(decorated_type)
{
}

unsigned int
array::size() const
{
	return size_;
}

std::shared_ptr<const type>
array::decorated_type() const
{
	return decorated_type_;
}

}}} //namespace scalpel::cpp::semantic_entities

