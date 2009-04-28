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

#ifndef SOCOA_CPP_SYNTAX_NODES_MEMBER_DECLARATION_MEMBER_DECLARATOR_LIST_HPP
#define SOCOA_CPP_SYNTAX_NODES_MEMBER_DECLARATION_MEMBER_DECLARATOR_LIST_HPP

#include <boost/optional.hpp>
#include "composite_node.hpp"
#include "member_declarator_list.hpp"
#include "decl_specifier_seq.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

/**
member_declaration_member_declarator_list
	= !(member_declaration_decl_specifier_seq >> !s) >> !(member_declarator_list >> !s) >> ch_p(';')
;
*/
class member_declaration_member_declarator_list: public composite_node
{
	public:
		member_declaration_member_declarator_list
		(
			boost::optional<decl_specifier_seq>&& decl_specifier_seq_node,
			boost::optional<space>&& post_decl_specifier_seq_space_node,
			boost::optional<member_declarator_list>&& member_declarator_list_node,
			boost::optional<space>&& post_member_declarator_list_space_node
		);

		member_declaration_member_declarator_list(const member_declaration_member_declarator_list& o);

		member_declaration_member_declarator_list(member_declaration_member_declarator_list&& o);

		const member_declaration_member_declarator_list&
		operator=(const member_declaration_member_declarator_list& o);

		inline
		const boost::optional<const decl_specifier_seq&>
		get_decl_specifier_seq() const;

		inline
		const boost::optional<const member_declarator_list&>
		get_member_declarator_list() const;

	private:
		void
		update_node_list();

		boost::optional<decl_specifier_seq> decl_specifier_seq_;
		boost::optional<space> post_decl_specifier_seq_space_;
		boost::optional<member_declarator_list> member_declarator_list_;
		boost::optional<space> post_member_declarator_list_space_;
};

inline
const boost::optional<const decl_specifier_seq&>
member_declaration_member_declarator_list::get_decl_specifier_seq() const
{
	return boost::optional<const decl_specifier_seq&>(decl_specifier_seq_);
}

inline
const boost::optional<const member_declarator_list&>
member_declaration_member_declarator_list::get_member_declarator_list() const
{
	return boost::optional<const member_declarator_list&>(member_declarator_list_);
}

}}} //namespace socoa::cpp::syntax_nodes

#endif
