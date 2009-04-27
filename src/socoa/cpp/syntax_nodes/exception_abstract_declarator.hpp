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

#ifndef SOCOA_CPP_SYNTAX_NODES_EXCEPTION_ABSTRACT_DECLARATOR_HPP
#define SOCOA_CPP_SYNTAX_NODES_EXCEPTION_ABSTRACT_DECLARATOR_HPP

#include <boost/optional.hpp>
#include "composite_node.hpp"
#include "type_specifier_seq.hpp"
#include "space.hpp"
#include "abstract_declarator.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

/**
exception_abstract_declarator
	= type_specifier_seq >> !s >> abstract_declarator
;
*/
class exception_abstract_declarator: public composite_node
{
	public:
		exception_abstract_declarator
		(
			type_specifier_seq&& type_specifier_seq_node,
			boost::optional<space>&& post_type_specifier_seq_space_node,
			abstract_declarator&& abstract_declarator_node
		);

		exception_abstract_declarator(const exception_abstract_declarator& o);

		exception_abstract_declarator(exception_abstract_declarator&& o);

		const exception_abstract_declarator&
		operator=(const exception_abstract_declarator& o);

	private:
		void
		update_node_list();

		type_specifier_seq type_specifier_seq_;
		boost::optional<space> post_type_specifier_seq_space_;
		abstract_declarator abstract_declarator_;
};

}}} //namespace socoa::cpp::syntax_nodes

#endif
