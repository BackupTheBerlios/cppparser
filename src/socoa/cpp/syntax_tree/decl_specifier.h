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

#ifndef SOCOA_CPP_SYNTAX_TREE_DECL_SPECIFIER_H
#define SOCOA_CPP_SYNTAX_TREE_DECL_SPECIFIER_H

#include <memory>
#include <boost/variant.hpp>
#include "type_specifier.h"
#include "function_specifier.h"
#include "storage_class_specifier.h"

namespace socoa { namespace cpp { namespace syntax_tree
{

typedef
	boost::variant
	<
		type_specifier,
		function_specifier,
		storage_class_specifier
	>
	decl_specifier_t
;

class decl_specifier: public decl_specifier_t
{
	public:
		decl_specifier(const type_specifier& o): decl_specifier_t(o){}
		decl_specifier(const function_specifier& o): decl_specifier_t(o){}
		decl_specifier(const storage_class_specifier& o): decl_specifier_t(o){}
};

}}} //namespace socoa::cpp::syntax_tree

#endif
