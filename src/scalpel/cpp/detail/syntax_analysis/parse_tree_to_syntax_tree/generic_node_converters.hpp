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

#ifndef SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_PARSE_TREE_TO_SYNTAX_TREE_NODE_CONVERTERS_HPP
#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_PARSE_TREE_TO_SYNTAX_TREE_NODE_CONVERTERS_HPP

#include <string>
#include <iostream>
#include <boost/utility/enable_if.hpp>
#include "../../../syntax_tree.hpp"
#include "../grammar.hpp"
#include "conversion_functions.hpp"
#include "sequence_node_converter_fwd.hpp"
#include "alternative_node_converter_fwd.hpp"
#include "special_conversion_functions_fwd.hpp"

#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_ID_SPECIALIZATION(id, return_type, convert_function)\
template<class T>											\
struct node_converter_from_id<T, grammar::parser_id::id>	\
{															\
	static													\
	syntax_nodes::return_type								\
	convert(const tree_node_t& node)						\
	{														\
		return convert_##convert_function(node);			\
	}														\
};

#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_TYPE_SPECIALIZATION(return_type, convert_function)\
template<>													\
struct node_converter_from_type<syntax_nodes::return_type>	\
{															\
	static													\
	syntax_nodes::return_type								\
	convert(const tree_node_t& node)						\
	{														\
		return convert_##convert_function(node);			\
	}														\
};

#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION(correct_id, node_type)\
template<>													\
struct id_checker<syntax_nodes::node_type>					\
{															\
	static													\
	bool													\
	check(const boost::spirit::parser_id id)				\
	{														\
		return id == id_t::correct_id;						\
	}														\
};

#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION(id, return_type, convert_function)\
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_ID_SPECIALIZATION(id, return_type, convert_function)\
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_TYPE_SPECIALIZATION(return_type, convert_function)\
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION(id, return_type)

#define SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22(id, return_type)\
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_ID_SPECIALIZATION(id, return_type, node<syntax_nodes::return_type>)\
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION(id, return_type)

namespace scalpel { namespace cpp { namespace detail { namespace syntax_analysis { namespace parse_tree_to_syntax_tree
{

/**
Calls the convert_* function corresponding to the given grammar's parser id.
*/
template<class T, int ParserId>
struct node_converter_from_id;

/**
Calls the convert_* function corresponding to the given syntax node type.
*/
template<class T>
struct node_converter_from_type;

template<class SyntaxNodeT>
struct id_checker;



/*
 * Utility types for type traits
 */
typedef char yes_type;

struct no_type
{
	char padding[8];
};



/*
 * sequence_node type traits
 */
namespace sequence_node
{
	template<class T>
	static yes_type
	check_sig(typename T::tail_sequence_node_t*);

	template<class T>
	static no_type
	check_sig(...);
}

template<class T>
struct is_sequence_node
{
	static const bool value = sizeof(sequence_node::check_sig<T>(0)) == sizeof(yes_type);
};



/*
 * alternative_node type traits
 */
namespace alternative_node
{
	template<class T>
	static yes_type
	check_sig(typename T::tail_alternative_node_t*);

	template<class T>
	static no_type
	check_sig(...);
}

template<class T>
struct is_alternative_node
{
	static const bool value = sizeof(alternative_node::check_sig<T>(0)) == sizeof(yes_type);
};



/*
 * list_node type traits
 */
namespace list_node
{
	template<class T>
	static yes_type
	check_sig(typename T::item*);

	template<class T>
	static no_type
	check_sig(...);
}

template<class T>
struct is_list_node
{
	static const bool value = sizeof(list_node::check_sig<T>(0)) == sizeof(yes_type);
};



/*
 * optional_node type traits
 */
template<class T>
struct is_optional_node
{
	static const bool value = false;
};

template<class T>
struct is_optional_node<syntax_nodes::optional_node<T>>
{
	static const bool value = true;
};



/*
 * simple_text_node type traits
 */
template<class T>
struct is_simple_text_node
{
	static const bool value = false;
};

template<const std::string& Text>
struct is_simple_text_node<syntax_nodes::simple_text_node<Text>>
{
	static const bool value = true;
};





template<class SyntaxNodeT>
inline
SyntaxNodeT
convert_node
(
	const tree_node_t& node,
	typename boost::disable_if<is_sequence_node<SyntaxNodeT>>::type* = 0,
	typename boost::disable_if<is_alternative_node<SyntaxNodeT>>::type* = 0,
	typename boost::disable_if<is_list_node<SyntaxNodeT>>::type* = 0,
	typename boost::disable_if<is_optional_node<SyntaxNodeT>>::type* = 0,
	typename boost::disable_if<is_simple_text_node<SyntaxNodeT>>::type* = 0
)
{
	return node_converter_from_type<SyntaxNodeT>::convert(node);
}

//overload for sequence nodes
template<class SyntaxNodeT>
inline
SyntaxNodeT
convert_node(const tree_node_t& node, typename SyntaxNodeT::tail_sequence_node_t* = 0)
{
	return convert_sequence_node<SyntaxNodeT>(node);
}

//overload for alternative nodes
template<class SyntaxNodeT>
inline
SyntaxNodeT
convert_node(const tree_node_t& node, typename SyntaxNodeT::tail_alternative_node_t* = 0)
{
	return convert_alternative_node<SyntaxNodeT>(node);
}

//overload for list nodes
template<class SyntaxNodeT>
inline
SyntaxNodeT
convert_node(const tree_node_t& node, typename boost::enable_if<is_list_node<SyntaxNodeT>>::type* = 0)
{
	return convert_list_node<SyntaxNodeT>(node);
}

//overload for optional nodes
template<class SyntaxNodeT>
inline
SyntaxNodeT
convert_node(const tree_node_t& node, typename boost::enable_if<is_optional_node<SyntaxNodeT>>::type* = 0)
{
	return convert_optional_node<SyntaxNodeT>(node);
}

//overload for simple_text nodes
template<class SyntaxNodeT>
inline
SyntaxNodeT
convert_node(const tree_node_t& node, typename boost::enable_if<is_simple_text_node<SyntaxNodeT>>::type* = 0)
{
	return convert_simple_text_node<SyntaxNodeT>(node);
}



//other specializations
//SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION(id::ASM_DEFINITION,
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ASSIGNMENT_EXPRESSION,
	assignment_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	ASSIGNMENT_EXPRESSION_CONDITION,
	assignment_expression_condition,
	assignment_expression_condition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ASSIGNMENT_EXPRESSION_FIRST_PART,
	assignment_expression::first_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	ASSIGNMENT_EXPRESSION_FIRST_PART_SEQ,
	assignment_expression::first_part_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ASSIGNMENT_EXPRESSION_LAST_PART,
	assignment_expression::last_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BASE_CLAUSE,
	base_clause
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BASE_SPECIFIER,
	base_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BLOCK_DECLARATION,
	block_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BOOLEAN_LITERAL,
	boolean_literal
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BREAK_STATEMENT,
	break_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BUILT_IN_TYPE_SPECIFIER,
	built_in_type_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CAST_EXPRESSION,
	cast_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	CHARACTER_LITERAL,
	character_literal,
	character_literal
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	CLASS_HEAD,
	class_head,
	class_head
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CLASS_SPECIFIER,
	class_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	COMPOUND_STATEMENT,
	compound_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CONDITION,
	condition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CONDITIONAL_EXPRESSION,
	conditional_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CONTINUE_STATEMENT,
	continue_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CONVERSION_FUNCTION_ID,
	conversion_function_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CTOR_INITIALIZER,
	ctor_initializer
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECL_SPECIFIER,
	decl_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECLARATION,
	declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECLARATOR,
	declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECLARATOR_ID,
	declarator_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DELETE_EXPRESSION,
	delete_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DESTRUCTOR_NAME,
	destructor_name
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_DECLARATOR,
	direct_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_DECLARATOR_ARRAY_PART,
	direct_declarator::array_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_DECLARATOR_FUNCTION_PART,
	direct_declarator::function_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_DECLARATOR_FIRST_PART,
	direct_declarator::first_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_DECLARATOR_LAST_PART,
	direct_declarator::last_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	DIRECT_DECLARATOR_LAST_PART_SEQ,
	direct_declarator::last_part_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DO_WHILE_STATEMENT,
	do_while_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ELABORATED_TYPE_SPECIFIER,
	elaborated_type_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	EMPTY_INITIALIZER_LIST_INITIALIZER_CLAUSE,
	empty_initializer_list_initializer_clause,
	empty_initializer_list_initializer_clause
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EQUAL_INITIALIZER,
	equal_initializer
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXPRESSION,
	expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXPRESSION_STATEMENT,
	expression_statement
)
//            id::EXPLICIT_INSTANTIATION,
//            id::EXPLICIT_SPECIALIZATION,
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	FLOATING_LITERAL,
	floating_literal,
	floating_literal
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	FOR_INIT_STATEMENT,
	for_init_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	FOR_STATEMENT,
	for_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	FUNCTION_DEFINITION,
	function_definition,
	function_definition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	FUNCTION_SPECIFIER,
	function_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	GOTO_STATEMENT,
	goto_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ID_EXPRESSION,
	id_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	IDENTIFIER,
	identifier,
	identifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	IDENTIFIER_OR_TEMPLATE_ID,
	identifier_or_template_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	INIT_DECLARATOR,
	init_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	INITIALIZER,
	initializer
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	INITIALIZER_CLAUSE,
	initializer_clause
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	INITIALIZER_LIST_INITIALIZER_CLAUSE,
	initializer_list_initializer_clause,
	initializer_list_initializer_clause
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	INTEGER_LITERAL,
	integer_literal,
	integer_literal
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ITERATION_STATEMENT,
	iteration_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	JUMP_STATEMENT,
	jump_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	LABELED_STATEMENT,
	labeled_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	LITERAL,
	literal
)
//            id::LINKAGE_SPECIFICATION,
	//id::NAMESPACE_ALIAS_DEFINITION,
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEM_INITIALIZER,
	mem_initializer
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEM_INITIALIZER_ID,
	mem_initializer_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATION,
	member_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATION_FUNCTION_DEFINITION,
	member_declaration_function_definition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	MEMBER_DECLARATION_MEMBER_DECLARATOR_LIST,
	member_declaration_member_declarator_list,
	member_declaration_member_declarator_list
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATION_UNQUALIFIED_ID,
	member_declaration_unqualified_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATOR,
	member_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATOR_BIT_FIELD_MEMBER,
	member_declarator_bit_field_member
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATOR_DECLARATOR,
	member_declarator_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_SPECIFICATION_PART,
	member_specification_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	MEMBER_SPECIFICATION_ACCESS_SPECIFIER,
	member_specification_access_specifier,
	member_specification_access_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NAMESPACE_DEFINITION,
	namespace_definition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	NESTED_IDENTIFIER_OR_TEMPLATE_ID,
	nested_identifier_or_template_id,
	nested_identifier_or_template_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NESTED_NAME_SPECIFIER,
	nested_name_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NESTED_NAME_SPECIFIER_LAST_PART,
	nested_name_specifier::last_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	NESTED_NAME_SPECIFIER_LAST_PART_SEQ,
	nested_name_specifier::last_part_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NEW_EXPRESSION,
	new_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	OPERATOR_FUNCTION_ID,
	operator_function_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	PARAMETER_DECLARATION,
	parameter_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	PARAMETER_DECLARATION_LIST,
	parameter_declaration_list
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	PARAMETER_DECLARATION_CLAUSE,
	parameter_declaration_clause
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	POSTFIX_EXPRESSION_LAST_PART_SEQ,
	postfix_expression_last_part_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	POSTFIX_EXPRESSION,
	postfix_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	PRIMARY_EXPRESSION,
	primary_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	PTR_OPERATOR,
	ptr_operator,
	ptr_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	QUALIFIED_ID,
	qualified_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	QUALIFIED_NESTED_ID,
	qualified_nested_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	QUALIFIED_OPERATOR_FUNCTION_ID,
	qualified_operator_function_id,
	qualified_operator_function_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	QUALIFIED_TEMPLATE_ID,
	qualified_template_id,
	qualified_template_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	QUALIFIED_IDENTIFIER,
	qualified_identifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	RETURN_STATEMENT,
	return_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SELECTION_STATEMENT,
	selection_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SIMPLE_DECLARATION,
	simple_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SIMPLE_TYPE_SPECIFIER,
	simple_type_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	SIMPLE_TEMPLATE_TYPE_SPECIFIER,
	simple_template_type_specifier,
	simple_template_type_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	SPACE,
	space,
	space
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	STATEMENT,
	statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	STORAGE_CLASS_SPECIFIER,
	storage_class_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	STRING_LITERAL,
	string_literal,
	string_literal
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT,
	template_argument
)
/*SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	TEMPLATE_ARGUMENT_ASSIGNMENT_EXPRESSION,
	assignment_expression,
	assignment_expression
)*/
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_DECLARATION,
	template_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ID,
	template_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TRANSLATION_UNIT,
	translation_unit
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	TRY_BLOCK,
	try_block,
	try_block
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPE_ID,
	type_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_ID_SPECIALIZATION
(
	TYPE_NAME,
	identifier,
	identifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPE_SPECIFIER,
	type_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	UNARY_EXPRESSION,
	unary_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	UNARY_OPERATOR_UNARY_EXPRESSION,
	unary_operator_unary_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	UNQUALIFIED_ID,
	unqualified_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	USING_DECLARATION,
	using_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	USING_DIRECTIVE,
	using_directive
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	WHILE_STATEMENT,
	while_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	POSTFIX_EXPRESSION_FIRST_PART,
	postfix_expression::first_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SIMPLE_TYPE_SPECIFIER_POSTFIX_EXPRESSION,
	simple_type_specifier_postfix_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPENAME_EXPRESSION,
	typename_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	TEMPLATE_TYPENAME_EXPRESSION,
	template_typename_expression,
	template_typename_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DYNAMIC_CAST_EXPRESSION,
	dynamic_cast_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	STATIC_CAST_EXPRESSION,
	static_cast_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	REINTERPRET_CAST_EXPRESSION,
	reinterpret_cast_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CONST_CAST_EXPRESSION,
	const_cast_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	TYPEID_EXPRESSION,
	typeid_expression,
	typeid_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	TYPE_ID_TYPEID_EXPRESSION,
	type_id_typeid_expression,
	type_id_typeid_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	POSTFIX_EXPRESSION_LAST_PART,
	postfix_expression::last_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ROUND_BRACKETED_OPTIONAL_EXPRESSION,
	round_bracketed_optional_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DOT_ID_EXPRESSION,
	dot_id_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ARROW_ID_EXPRESSION,
	arrow_id_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	DOT_PSEUDO_DESTRUCTOR_NAME,
	dot_pseudo_destructor_name,
	dot_pseudo_destructor_name
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	ARROW_PSEUDO_DESTRUCTOR_NAME,
	arrow_pseudo_destructor_name,
	arrow_pseudo_destructor_name
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	IF_STATEMENT,
	if_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SWITCH_STATEMENT,
	switch_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CASE_STATEMENT,
	case_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DEFAULT_STATEMENT,
	default_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CLASSIC_LABELED_STATEMENT,
	classic_labeled_statement
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ROUND_BRACKETED_EXPRESSION,
	round_bracketed_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	HANDLER,
	handler
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	THROW_EXPRESSION,
	throw_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXCEPTION_DECLARATION,
	exception_declaration
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXCEPTION_DECLARATOR,
	exception_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXCEPTION_ABSTRACT_DECLARATOR,
	exception_abstract_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPE_SPECIFIER_SEQ,
	type_specifier_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_ABSTRACT_DECLARATOR,
	direct_abstract_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	PTR_OPERATOR_SEQ,
	ptr_operator_seq,
	list_node<syntax_nodes::ptr_operator_seq>
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ABSTRACT_DECLARATOR,
	abstract_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	FUNCTION_TRY_BLOCK,
	function_try_block,
	function_try_block
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	OPERATOR,
	operator_
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ARRAY_OPERATOR,
	array_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NEW_ARRAY_OPERATOR,
	new_array_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DELETE_ARRAY_OPERATOR,
	delete_array_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SIMPLE_OPERATOR,
	simple_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	CLASS_TEMPLATE_ELABORATED_SPECIFIER,
	class_template_elaborated_specifier,
	class_template_elaborated_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CLASS_ELABORATED_SPECIFIER,
	class_elaborated_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	ENUM_ELABORATED_SPECIFIER,
	enum_elaborated_specifier,
	enum_elaborated_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	TYPENAME_TEMPLATE_ELABORATED_SPECIFIER,
	typename_template_elaborated_specifier,
	typename_template_elaborated_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPENAME_ELABORATED_SPECIFIER,
	typename_elaborated_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPE_ID_NEW_EXPRESSION,
	type_id_new_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	NEW_TYPE_ID_NEW_EXPRESSION,
	new_type_id_new_expression,
	new_type_id_new_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
(
	NEW_PLACEMENT,
	new_placement,
	new_placement
)
//SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
//(
//	NEW_INITIALIZER,
//	new_initializer
//)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NEW_TYPE_ID,
	new_type_id
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NEW_DECLARATOR,
	new_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPEOF_EXPRESSION,
	typeof_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ENUM_SPECIFIER,
	enum_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SIMPLE_DELETE_EXPRESSION,
	simple_delete_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ARRAY_DELETE_EXPRESSION,
	array_delete_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BRACKETED_DECLARATOR,
	bracketed_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXCEPTION_SPECIFICATION,
	exception_specification
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DIRECT_NEW_DECLARATOR,
	direct_new_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	MEMBER_SPECIFICATION,
	member_specification
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	STATEMENT_SEQ,
	statement_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	SQUARE_BRACKETED_EXPRESSION,
	square_bracketed_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ACCESS_SPECIFIER,
	access_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ASSIGNMENT_OPERATOR,
	assignment_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CV_QUALIFIER,
	cv_qualifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	CV_QUALIFIER_SEQ,
	cv_qualifier_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	TYPE_ID_LIST,
	type_id_list
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_ID_CHECKER_SPECIALIZATION
(
	DECLARATION_SEQ,
	declaration_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	UNARY_OPERATOR,
	unary_operator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CLASS_KEY,
	class_key
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_LIST,
	template_argument_list
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPE_PARAMETER,
	type_parameter
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CLASS_TYPE_PARAMETER,
	class_type_parameter
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPENAME_TYPE_PARAMETER,
	typename_type_parameter
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	EXPLICIT_SPECIALIZATION,
	explicit_specialization
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_ASSIGNMENT_EXPRESSION,
	template_argument_assignment_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_ASSIGNMENT_EXPRESSION_FIRST_PART_SEQ,
	template_argument_assignment_expression_first_part_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_ASSIGNMENT_EXPRESSION_FIRST_PART,
	template_argument_assignment_expression_first_part
)
/*
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_ASSIGNMENT_EXPRESSION_LAST_PART,
	template_argument_assignment_expression_last_part
)
*/
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ROUND_BRACKETED_RIGHT_SHIFT_EXPRESSION,
	round_bracketed_right_shift_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ROUND_BRACKETED_GREATER_THAN_EXPRESSION,
	round_bracketed_greater_than_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_RIGHT_SHIFT_EXPRESSION,
	template_argument_right_shift_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_LESS_THAN_OR_EQUAL_TO_EXPRESSION,
	template_argument_less_than_or_equal_to_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_LESS_THAN_EXPRESSION,
	template_argument_less_than_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_GREATER_THAN_OR_EQUAL_TO_EXPRESSION,
	template_argument_greater_than_or_equal_to_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_GREATER_THAN_EXPRESSION,
	template_argument_greater_than_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_INEQUALITY_EXPRESSION,
	template_argument_inequality_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_EQUALITY_EXPRESSION,
	template_argument_equality_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_AND_EXPRESSION,
	template_argument_and_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_EXCLUSIVE_OR_EXPRESSION,
	template_argument_exclusive_or_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_INCLUSIVE_OR_EXPRESSION,
	template_argument_inclusive_or_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_LOGICAL_AND_EXPRESSION,
	template_argument_logical_and_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_LOGICAL_OR_EXPRESSION,
	template_argument_logical_or_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TEMPLATE_ARGUMENT_CONDITIONAL_EXPRESSION,
	template_argument_conditional_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	LEFT_SHIFT_EXPRESSION,
	left_shift_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CAST_EXPRESSION_FIRST_PART_SEQ,
	cast_expression_first_part_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECL_SPECIFIER_SEQ,
	decl_specifier_seq
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	INIT_DECLARATOR_LIST,
	init_declarator_list
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	BRACKETED_ABSTRACT_DECLARATOR,
	bracketed_abstract_declarator
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ASM_DEFINITION,
	asm_definition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	QUALIFIED_NAMESPACE_SPECIFIER,
	qualified_namespace_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	NAMESPACE_ALIAS_DEFINITION,
	namespace_alias_definition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	LINKAGE_SPECIFICATION,
	linkage_specification
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECLARATION_LINKAGE_SPECIFICATION,
	declaration_linkage_specification
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	DECLARATION_SEQ_LINKAGE_SPECIFICATION,
	declaration_seq_linkage_specification
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ENUMERATOR_LIST,
	enumerator_list
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	ENUMERATOR_DEFINITION,
	enumerator_definition
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	MEMBER_DECLARATOR_DECLARATOR_LAST_PART,
	member_declarator_declarator_last_part
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	PURE_SPECIFIER,
	pure_specifier
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	CONSTANT_INITIALIZER,
	constant_initializer
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	TYPE_ID_SIZEOF_EXPRESSION,
	type_id_sizeof_expression
)
SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION22
(
	UNARY_SIZEOF_EXPRESSION,
	unary_sizeof_expression
)

template<class SyntaxNodeT>
bool
check_id(const boost::spirit::parser_id id)
{
	return id_checker<SyntaxNodeT>::check(id);
}

}}}}} //namespace scalpel::cpp::detail::syntax_analysis::parse_tree_to_syntax_tree

#undef SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_SPECIALIZATION
#undef SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_ID_SPECIALIZATION
#undef SCALPEL_CPP_DETAIL_SYNTAX_ANALYSIS_NODE_CONVERTER_FROM_TYPE_SPECIALIZATION

#endif
