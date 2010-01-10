/*
Scalpel - Source Code Analysis, Libre and PortablE Library
Copyright © 2008 - 2010  Florian Goujeon

This file is part of Scalpel.

Scalpel is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Scalpel is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Scalpel.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCALPEL_CPP_SYNTAX_NODES_USING_DIRECTIVE_HPP
#define SCALPEL_CPP_SYNTAX_NODES_USING_DIRECTIVE_HPP

#include "identifier.hpp"
#include "nested_name_specifier.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

/**
\verbatim
using_directive
	= "using" >> !s >> "namespace" >> !s >> !(str_p("::") >> !s) >> !(nested_name_specifier >> !s) >> identifier >> !s >> ch_p(';')
;
\endverbatim
*/
typedef
	sequence_node
	<
		predefined_text_node<str::using_>,
		optional_node<space>,
		predefined_text_node<str::namespace_>,
		optional_node<space>,
		optional_node<predefined_text_node<str::double_colon>>,
		optional_node<space>,
		optional_node<nested_name_specifier>,
		optional_node<space>,
		identifier,
		optional_node<space>,
		predefined_text_node<str::semicolon>
	>
	using_directive
;

}}} //namespace scalpel::cpp::syntax_nodes

#endif
