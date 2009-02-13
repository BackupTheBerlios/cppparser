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

#include "using_directive.h"

namespace socoa { namespace cpp { namespace syntax_tree
{

using_directive::using_directive
(
    bool leading_double_colon,
    std::shared_ptr<nested_name_specifier> a_nested_name_specifier,
    identifier&& an_identifier
):
    leading_double_colon_(leading_double_colon),
//    nested_name_specifier_(a_nested_name_specifier),
    identifier_(an_identifier)
{
	if(a_nested_name_specifier) nested_name_specifier_ = *a_nested_name_specifier;
}

}}} //namespace socoa::cpp::syntax_tree

