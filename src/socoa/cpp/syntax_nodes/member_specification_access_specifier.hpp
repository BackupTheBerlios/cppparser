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

#ifndef SOCOA_CPP_SYNTAX_NODES_MEMBER_SPECIFICATION_ACCESS_SPECIFIER_HPP
#define SOCOA_CPP_SYNTAX_NODES_MEMBER_SPECIFICATION_ACCESS_SPECIFIER_HPP

#include "composite_node.hpp"
#include "access_specifier.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

class member_specification_access_specifier: public composite_node
{
	public:
		explicit
		member_specification_access_specifier
		(
			access_specifier&& a_access_specifier
		);

		member_specification_access_specifier(const member_specification_access_specifier& o);

		member_specification_access_specifier(member_specification_access_specifier&& o);

		const member_specification_access_specifier&
		operator=(const member_specification_access_specifier& o);

		inline
		const access_specifier&
	   	get_access_specifier() const;

	private:
		void
		update_node_list();

		access_specifier access_specifier_;
};

inline
const access_specifier&
member_specification_access_specifier::get_access_specifier() const
{
	return access_specifier_;
}

}}} //namespace socoa::cpp::syntax_nodes

#endif
