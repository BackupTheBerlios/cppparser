/*
Scalpel - Source Code Analysis, Libre and PortablE Library
Copyright © 2008, 2009  Florian Goujeon

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

#ifndef SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_PARSE_TREE_TO_SYNTAX_TREE_CONVERT_FUNCTIONS_HPP
#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_PARSE_TREE_TO_SYNTAX_TREE_CONVERT_FUNCTIONS_HPP

#include "../../../syntax_tree.hpp"
#include "typedefs.hpp"

namespace scalpel { namespace cpp { namespace detail { namespace syntax_analysis { namespace parse_tree_to_syntax_tree
{

syntax_nodes::arrow_pseudo_destructor_name
convert_arrow_pseudo_destructor_name(const tree_node_t& node);

syntax_nodes::assignment_expression_condition
convert_assignment_expression_condition(const tree_node_t& node);

syntax_nodes::character_literal
convert_character_literal(const tree_node_t& node);

syntax_nodes::class_head
convert_class_head(const tree_node_t& node);

syntax_nodes::class_template_elaborated_specifier
convert_class_template_elaborated_specifier(const tree_node_t& node);

syntax_nodes::cv_qualifier
convert_cv_qualifier(const tree_node_t& node);

syntax_nodes::delete_array_operator
convert_delete_array_operator(const tree_node_t& node);

syntax_nodes::direct_abstract_declarator
convert_direct_abstract_declarator(const tree_node_t& node);

syntax_nodes::dot_pseudo_destructor_name
convert_dot_pseudo_destructor_name(const tree_node_t& node);

syntax_nodes::empty_initializer_list_initializer_clause
convert_empty_initializer_list_initializer_clause(const tree_node_t& node);

syntax_nodes::enum_elaborated_specifier
convert_enum_elaborated_specifier(const tree_node_t& node);

syntax_nodes::enum_specifier
convert_enum_specifier(const tree_node_t& node);

syntax_nodes::floating_literal
convert_floating_literal(const tree_node_t& node);

syntax_nodes::function_definition
convert_function_definition(const tree_node_t& node);

syntax_nodes::function_try_block
convert_function_try_block(const tree_node_t& node);

syntax_nodes::identifier
convert_identifier(const tree_node_t& node);

syntax_nodes::initializer_list_initializer_clause
convert_initializer_list_initializer_clause(const tree_node_t& node);

syntax_nodes::integer_literal
convert_integer_literal(const tree_node_t& node);

syntax_nodes::member_declaration_function_definition
convert_member_declaration_function_definition(const tree_node_t& node);

syntax_nodes::member_declaration_member_declarator_list
convert_member_declaration_member_declarator_list(const tree_node_t& node);

syntax_nodes::member_declaration_unqualified_id
convert_member_declaration_unqualified_id(const tree_node_t& node);

syntax_nodes::member_declarator_bit_field_member
convert_member_declarator_bit_field_member(const tree_node_t& node);

syntax_nodes::member_declarator_declarator
convert_member_declarator_declarator(const tree_node_t& node);

syntax_nodes::member_specification_access_specifier
convert_member_specification_access_specifier(const tree_node_t& node);

syntax_nodes::nested_identifier_or_template_id
convert_nested_identifier_or_template_id(const tree_node_t& node);

syntax_nodes::nested_name_specifier::last_part
convert_nested_name_specifier_last_part(const tree_node_t& node);

syntax_nodes::nested_name_specifier
convert_nested_name_specifier(const tree_node_t& node);

syntax_nodes::new_array_operator
convert_new_array_operator(const tree_node_t& node);

syntax_nodes::new_placement
convert_new_placement(const tree_node_t& node);

syntax_nodes::new_type_id_new_expression
convert_new_type_id_new_expression(const tree_node_t& node);

syntax_nodes::parameter_declaration
convert_parameter_declaration(const tree_node_t& node);

syntax_nodes::ptr_operator
convert_ptr_operator(const tree_node_t& node);

syntax_nodes::qualified_operator_function_id
convert_qualified_operator_function_id(const tree_node_t& node);

syntax_nodes::qualified_template_id
convert_qualified_template_id(const tree_node_t& node);

syntax_nodes::simple_declaration
convert_simple_declaration(const tree_node_t& node);

syntax_nodes::simple_delete_expression
convert_simple_delete_expression(const tree_node_t& node);

syntax_nodes::simple_template_type_specifier
convert_simple_template_type_specifier(const tree_node_t& node);

syntax_nodes::simple_type_specifier_postfix_expression
convert_simple_type_specifier_postfix_expression(const tree_node_t& node);

syntax_nodes::space
convert_space(const tree_node_t& node);

syntax_nodes::string_literal
convert_string_literal(const tree_node_t& node);

syntax_nodes::switch_statement
convert_switch_statement(const tree_node_t& node);

syntax_nodes::template_declaration
convert_template_declaration(const tree_node_t& node);

syntax_nodes::template_id
convert_template_id(const tree_node_t& node);

syntax_nodes::template_typename_expression
convert_template_typename_expression(const tree_node_t& node);

syntax_nodes::throw_expression
convert_throw_expression(const tree_node_t& node);

syntax_nodes::translation_unit
convert_translation_unit(const tree_node_t& node);

syntax_nodes::try_block
convert_try_block(const tree_node_t& node);

syntax_nodes::type_id
convert_type_id(const tree_node_t& node);

syntax_nodes::type_id_sizeof_expression
convert_type_id_sizeof_expression(const tree_node_t& node);

syntax_nodes::type_id_typeid_expression
convert_type_id_typeid_expression(const tree_node_t& node);

syntax_nodes::typeid_expression
convert_typeid_expression(const tree_node_t& node);

syntax_nodes::typeof_expression
convert_typeof_expression(const tree_node_t& node);

syntax_nodes::typename_elaborated_specifier
convert_typename_elaborated_specifier(const tree_node_t& node);

syntax_nodes::typename_expression
convert_typename_expression(const tree_node_t& node);

syntax_nodes::typename_template_elaborated_specifier
convert_typename_template_elaborated_specifier(const tree_node_t& node);

syntax_nodes::unary_operator_unary_expression
convert_unary_operator_unary_expression(const tree_node_t& node);

syntax_nodes::unary_sizeof_expression
convert_unary_sizeof_expression(const tree_node_t& node);

}}}}} //namespace scalpel::cpp::detail::syntax_analysis

#endif
