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

#ifndef SOCOA_CPP_SYNTAX_TREE_PARAMETER_DECLARATION_CLAUSE_H
#define SOCOA_CPP_SYNTAX_TREE_PARAMETER_DECLARATION_CLAUSE_H

#include <memory>
#include "../../util/sequence.h"

namespace socoa { namespace cpp { namespace syntax_tree
{

class parameter_declaration;

struct parameter_declaration_clause
{
    const std::shared_ptr<util::sequence<parameter_declaration, util::extern_strings::comma>> parameter_declaration_list_;
    const bool trailing_comma_;
    const bool ellipsis_;
};

}}} //namespace socoa::cpp::syntax_tree

#endif