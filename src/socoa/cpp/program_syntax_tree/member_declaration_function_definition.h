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

#ifndef SOCOA_CPP_PROGRAM_SYNTAX_TREE_MEMBER_DECLARATION_FUNCTION_DEFINITION_H
#define SOCOA_CPP_PROGRAM_SYNTAX_TREE_MEMBER_DECLARATION_FUNCTION_DEFINITION_H

#include "member_declaration.h"
#include "function_definition.h"

namespace socoa { namespace cpp { namespace program_syntax_tree
{

class member_declaration_function_definition: public member_declaration
{
    public:
        explicit member_declaration_function_definition
        (
            function_definition&& a_function_definition
        );

        const function_definition&
        get_function_definition() const;

        SOCOA_CPP_DEFINE_VISITABLE()

    private:
        function_definition function_definition_;
};

}}} //namespace socoa::cpp::program_syntax_tree

#endif