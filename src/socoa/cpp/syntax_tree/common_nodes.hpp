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

#ifndef SOCOA_CPP_SYNTAX_TREE_COMMON_NODES_HPP
#define SOCOA_CPP_SYNTAX_TREE_COMMON_NODES_HPP

#include <string>
#include "leaf_node.hpp"

namespace socoa { namespace cpp { namespace syntax_tree
{

extern const leaf_node ampersand;
extern const leaf_node asterisk;
extern const leaf_node closing_bracket;
extern const leaf_node comma;
extern const leaf_node empty;
extern const leaf_node opening_bracket;
extern const leaf_node semicolon;

}}} //namespace socoa::cpp::syntax_tree

#endif
