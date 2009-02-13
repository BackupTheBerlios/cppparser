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

#ifndef SOCOA_CPP_SYNTAX_TREE_USING_DECLARATION_H
#define SOCOA_CPP_SYNTAX_TREE_USING_DECLARATION_H

#include <memory>
#include <boost/optional.hpp>
#include "visitor.h"
#include "member_declaration.h"
#include "block_declaration.h"
#include "nested_name_specifier.h"

namespace socoa { namespace cpp { namespace syntax_tree
{

class unqualified_id;

class using_declaration: public member_declaration, public block_declaration
{
	public:
		using_declaration
		(
			bool typename_keyword,
			bool leading_double_colon,
			std::shared_ptr<nested_name_specifier> a_nested_name_specifier,
			std::shared_ptr<unqualified_id> an_unqualified_id
		);

		inline
		bool
		has_typename_keyword() const;

		inline
		bool
		has_leading_double_colon() const;

		inline
		const boost::optional<const nested_name_specifier&>
		get_nested_name_specifier() const;

		inline
		const std::shared_ptr<const unqualified_id>
		get_unqualified_id() const;

		SOCOA_CPP_DEFINE_VISITABLE()

	private:
		bool typename_keyword_;
		bool leading_double_colon_;
		boost::optional<nested_name_specifier> nested_name_specifier_;
		std::shared_ptr<unqualified_id> unqualified_id_;
};

inline
bool
using_declaration::has_typename_keyword() const
{
	return typename_keyword_;
}

inline
bool
using_declaration::has_leading_double_colon() const
{
	return leading_double_colon_;
}

inline
const boost::optional<const nested_name_specifier&>
using_declaration::get_nested_name_specifier() const
{
	return boost::optional<const nested_name_specifier&>(nested_name_specifier_);
}

inline
const std::shared_ptr<const unqualified_id>
using_declaration::get_unqualified_id() const
{
	return unqualified_id_;
}

}}} //namespace socoa::cpp::syntax_tree

#endif
