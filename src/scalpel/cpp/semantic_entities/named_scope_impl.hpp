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

#ifndef SCALPEL_CPP_SEMANTIC_ENTITIES_SCOPE_IMPL_HPP
#define SCALPEL_CPP_SEMANTIC_ENTITIES_SCOPE_IMPL_HPP

#include "named_scope.hpp"
#include "named_entity.hpp"
#include <list>

namespace scalpel { namespace cpp { namespace semantic_entities
{

class named_scope_impl: public boost::noncopyable
{
	public:
		named_scope_impl();

		named_scope_impl(named_scope_impl&& s);

		const named_scope_impl&
		operator=(named_scope_impl&& s);

		named_scope::named_scope_iterator_range
		named_scopes();

		named_scope::named_scope_const_iterator_range
		named_scopes() const;

		void
		add_to_named_scopes(std::shared_ptr<named_scope> s);

		named_scope::named_entity_iterator_range
		named_entities();

		named_scope::named_entity_const_iterator_range
		named_entities() const;

		void
		add_to_named_entities(std::shared_ptr<named_entity> n);

	private:
		named_scope::named_scopes_t named_scopes_;
		named_scope::named_entities_t named_entities_;
};

}}} //namespace scalpel::cpp::semantic_entities

#endif
