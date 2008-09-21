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

#ifndef SOCOA_CPP_PROGRAM_SYNTAX_TREE_H
#define SOCOA_CPP_PROGRAM_SYNTAX_TREE_H

#include "program_syntax_tree/identifier.h"
#include "program_syntax_tree/id_expression.h"
#include "program_syntax_tree/nested_name_specifier.h"
#include "program_syntax_tree/nested_name_specifier_part.h"
#include "program_syntax_tree/nested_name_specifier_template_id.h"
#include "program_syntax_tree/declaration_seq.h"
#include "program_syntax_tree/declaration.h"
#include "program_syntax_tree/simple_declaration.h"
#include "program_syntax_tree/decl_specifier_seq.h"
#include "program_syntax_tree/decl_specifier.h"
#include "program_syntax_tree/type_specifier.h"
#include "program_syntax_tree/simple_type_specifier.h"
#include "program_syntax_tree/identifier_or_template_id.h"
#include "program_syntax_tree/namespace_definition.h"
#include "program_syntax_tree/init_declarator_list.h"
#include "program_syntax_tree/init_declarator.h"
#include "program_syntax_tree/declarator.h"
#include "program_syntax_tree/direct_declarator.h"
#include "program_syntax_tree/direct_declarator_part.h"
#include "program_syntax_tree/function_direct_declarator_part.h"
#include "program_syntax_tree/array_direct_declarator_part.h"
#include "program_syntax_tree/ptr_operator.h"
#include "program_syntax_tree/cv_qualifier_seq.h"
#include "program_syntax_tree/cv_qualifier.h"
#include "program_syntax_tree/declarator_id.h"
#include "program_syntax_tree/parameter_declaration_clause.h"
#include "program_syntax_tree/parameter_declaration_list.h"
#include "program_syntax_tree/parameter_declaration.h"
#include "program_syntax_tree/function_definition.h"
#include "program_syntax_tree/class_specifier.h"
#include "program_syntax_tree/class_head.h"
#include "program_syntax_tree/class_key.h"
#include "program_syntax_tree/member_specification.h"
#include "program_syntax_tree/template_declaration.h"
#include "program_syntax_tree/template_id.h"

#endif