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

#ifndef SOCOA_CPP_SYNTAX_TREE_MEM_INITIALIZER_LIST_H
#define SOCOA_CPP_SYNTAX_TREE_MEM_INITIALIZER_LIST_H

#include "../../util/sequence.h"
#include "../../util/extern_strings.h"
#include "mem_initializer.h"

namespace socoa { namespace cpp { namespace syntax_tree
{

typedef
    util::sequence<mem_initializer, util::extern_strings::comma>
    mem_initializer_list_t
;

}}} //namespace socoa::cpp::syntax_tree

#endif
