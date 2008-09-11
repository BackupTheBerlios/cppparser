/*
Socoa - Source Code Analysis Library
Copyright © 2008  Florian Goujeon

This file is part of Socoa.

Socoa is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

Socoa is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Socoa.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SOCOA_CPP_PROGRAM_SYNTAX_TREE_template_declaration_H
#define SOCOA_CPP_PROGRAM_SYNTAX_TREE_template_declaration_H

#include <memory>
#include "declaration.h"

namespace socoa { namespace cpp { namespace program_syntax_tree
{

class template_declaration: public declaration
{
    public:
        template_declaration(bool exported, std::shared_ptr<declaration> declaration_part);

        bool
        exported() const;

        const std::shared_ptr<declaration>
        declaration_part() const;

        void
        accept(visitor& a_visitor) const;

    private:
        bool m_exported;
        //template_parameter_list m_template_parameter_list;
        std::shared_ptr<declaration> m_declaration_part;
};

}}} //namespace socoa::cpp::program_syntax_tree

#endif