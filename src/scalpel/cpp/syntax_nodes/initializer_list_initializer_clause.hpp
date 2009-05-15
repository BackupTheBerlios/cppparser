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

#ifndef SCALPEL_CPP_SYNTAX_NODES_INITIALIZER_LIST_INITIALIZER_CLAUSE_HPP
#define SCALPEL_CPP_SYNTAX_NODES_INITIALIZER_LIST_INITIALIZER_CLAUSE_HPP

#include "composite_node.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

class initializer_list_initializer_clause: public composite_node
{
	public:
		initializer_list_initializer_clause
		(
		);

		initializer_list_initializer_clause(const initializer_list_initializer_clause& o);

		initializer_list_initializer_clause(initializer_list_initializer_clause&& o);

		const initializer_list_initializer_clause&
		operator=(const initializer_list_initializer_clause& o);

	private:
		void
		update_node_list();
};

}}} //namespace scalpel::cpp::syntax_nodes

#endif