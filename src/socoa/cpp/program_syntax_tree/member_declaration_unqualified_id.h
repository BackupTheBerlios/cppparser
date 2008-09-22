/*
Socoa - Source Code Analysis Library
Copyright © 2008  Florian Goujeon

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

#ifndef SOCOA_CPP_PROGRAM_SYNTAX_TREE_MEMBER_DECLARATION_UNQUALIFIED_ID_H
#define SOCOA_CPP_PROGRAM_SYNTAX_TREE_MEMBER_DECLARATION_UNQUALIFIED_ID_H

#include "member_declaration.h"
#include "nested_name_specifier.h"

namespace socoa { namespace cpp { namespace program_syntax_tree
{

class unqualified_id;

class member_declaration_unqualified_id: public member_declaration
{
    public:
        member_declaration_unqualified_id
        (
            bool leading_double_colon,
            nested_name_specifier&& a_nested_name_specifier,
            bool template_keyword,
            std::shared_ptr<unqualified_id> id
        );

        bool
        has_leading_double_colon() const;

        const nested_name_specifier&
        get_nested_name_specifier() const;

        bool
        has_template_keyword() const;

        const std::shared_ptr<unqualified_id>
        get_unqualified_id() const;

        SOCOA_CPP_DEFINE_VISITABLE()

    private:
        bool leading_double_colon_;
        nested_name_specifier nested_name_specifier_;
        bool template_keyword_;
        std::shared_ptr<unqualified_id> unqualified_id_;
};

}}} //namespace socoa::cpp::program_syntax_tree

#endif