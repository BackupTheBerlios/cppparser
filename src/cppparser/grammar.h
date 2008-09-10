/*
CppParser - Standard C++ programming language parsing library
Copyright © 2008  Florian Goujeon

This file is part of CppParser.

CppParser is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

CppParser is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CppParser.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CPPPARSER_GRAMMAR_H
#define CPPPARSER_GRAMMAR_H

#include <boost/spirit.hpp>
#include <boost/spirit/include/classic_ast.hpp>

namespace cppparser
{

class grammar: public boost::spirit::grammar<grammar>
{
    public:
        struct configuration;

        grammar(configuration& a_configuration):
            m_configuration(a_configuration)
        {
        }

        struct configuration
        {
            configuration():
                skip_function_bodies(false),
                enable_typeof_support(true),
                enable_restrict_support(true)
            {
            }

            bool skip_function_bodies;

            bool enable_typeof_support;
            bool enable_restrict_support;
        };

        enum parser_id
        {
            FILE,
            SOURCE_CHARACTER_SET,
            KEYWORD,
            EXPORT_KEYWORD,

            HEX_QUAD,
            UNIVERSAL_CHARACTER_NAME,
            IDENTIFIER,
            NONDIGIT,
            LITERAL,
            INTEGER_LITERAL,
            DECIMAL_LITERAL,
            OCTAL_LITERAL,
            HEXADECIMAL_LITERAL,
            HEXADECIMAL_DIGIT,
            OCTAL_DIGIT,
            NONZERO_DIGIT,
            INTEGER_SUFFIX,
            UNSIGNED_SUFFIX,
            LONG_SUFFIX,
            LONG_LONG_SUFFIX,
            CHARACTER_LITERAL,
            C_CHAR_SEQUENCE,
            C_CHAR,
            ESCAPE_SEQUENCE,
            SIMPLE_ESCAPE_SEQUENCE,
            OCTAL_ESCAPE_SEQUENCE,
            HEXADECIMAL_ESCAPE_SEQUENCE,
            FLOATING_LITERAL,
            FRACTIONAL_CONSTANT,
            EXPONENT_PART,
            DIGIT_SEQUENCE,
            FLOATING_SUFFIX,
            STRING_LITERAL,
            S_CHAR_SEQUENCE,
            S_CHAR,
            BOOLEAN_LITERAL,

            TRANSLATION_UNIT,

            PRIMARY_EXPRESSION,
            ID_EXPRESSION,
            UNQUALIFIED_ID,
            QUALIFIED_ID,
            NESTED_NAME_SPECIFIER,
            CLASS_OR_NAMESPACE_NAME,
            POSTFIX_EXPRESSION,
            EXPRESSION_LIST,
            PSEUDO_DESTRUCTOR_NAME,
            UNARY_EXPRESSION,
            UNARY_OPERATOR,
            NEW_EXPRESSION,
            NEW_PLACEMENT,
            NEW_TYPE_ID,
            NEW_DECLARATOR,
            DIRECT_NEW_DECLARATOR,
            NEW_INITIALIZER,
            DELETE_EXPRESSION,
            CAST_EXPRESSION,
            PM_EXPRESSION,
            MULTIPLICATIVE_EXPRESSION,
            ADDITIVE_EXPRESSION,
            SHIFT_EXPRESSION,
            TEMPLATE_ARGUMENT_SHIFT_EXPRESSION,
            RELATIONAL_EXPRESSION,
            TEMPLATE_ARGUMENT_RELATIONAL_EXPRESSION,
            EQUALITY_EXPRESSION,
            TEMPLATE_ARGUMENT_EQUALITY_EXPRESSION,
            AND_EXPRESSION,
            TEMPLATE_ARGUMENT_AND_EXPRESSION,
            EXCLUSIVE_OR_EXPRESSION,
            TEMPLATE_ARGUMENT_EXCLUSIVE_OR_EXPRESSION,
            INCLUSIVE_OR_EXPRESSION,
            TEMPLATE_ARGUMENT_INCLUSIVE_OR_EXPRESSION,
            LOGICAL_AND_EXPRESSION,
            TEMPLATE_ARGUMENT_LOGICAL_AND_EXPRESSION,
            LOGICAL_OR_EXPRESSION,
            TEMPLATE_ARGUMENT_LOGICAL_OR_EXPRESSION,
            CONDITIONAL_EXPRESSION,
            TEMPLATE_ARGUMENT_CONDITIONAL_EXPRESSION,
            ASSIGNMENT_EXPRESSION,
            TEMPLATE_ARGUMENT_ASSIGNMENT_EXPRESSION,
            ASSIGNMENT_OPERATOR,
            EXPRESSION,
            CONSTANT_EXPRESSION,

            STATEMENT,
            LABELED_STATEMENT,
            EXPRESSION_STATEMENT,
            COMPOUND_STATEMENT,
            STATEMENT_SEQ,
            SELECTION_STATEMENT,
            CONDITION,
            CONDITION_TYPE_SPECIFIER_SEQ,
            ITERATION_STATEMENT,
            FOR_INIT_STATEMENT,
            JUMP_STATEMENT,
            DECLARATION_STATEMENT,

            DECLARATION_SEQ,
            DECLARATION,
            BLOCK_DECLARATION,
            SIMPLE_DECLARATION,
            SIMPLE_DECLARATION_DECL_SPECIFIER_SEQ,
            DECL_SPECIFIER,
            DECL_SPECIFIER_SEQ,
            STORAGE_CLASS_SPECIFIER,
            FUNCTION_SPECIFIER,
            TYPEDEF_NAME,
            TYPE_SPECIFIER,
            SIMPLE_TYPE_SPECIFIER,
            TYPE_NAME,
            ELABORATED_TYPE_SPECIFIER,
            ENUM_NAME,
            ENUM_SPECIFIER,
            ENUMERATOR_LIST,
            ENUMERATOR_DEFINITION,
            ENUMERATOR,
            NAMESPACE_NAME,
            ORIGINAL_NAMESPACE_NAME,
            NAMESPACE_DEFINITION,
            NAMED_NAMESPACE_DEFINITION,
            UNNAMED_NAMESPACE_DEFINITION,
            NAMESPACE_BODY,
            NAMESPACE_ALIAS,
            NAMESPACE_ALIAS_DEFINITION,
            QUALIFIED_NAMESPACE_SPECIFIER,
            USING_DECLARATION,
            USING_DIRECTIVE,
            ASM_DEFINITION,
            LINKAGE_SPECIFICATION,

            INIT_DECLARATOR_LIST,
            INIT_DECLARATOR,
            DECLARATOR,
            DIRECT_DECLARATOR,
            PTR_OPERATOR,
            CV_QUALIFIER_SEQ,
            CV_QUALIFIER,
            DECLARATOR_ID,
            TYPE_ID,
            TYPE_SPECIFIER_SEQ,
            ABSTRACT_DECLARATOR,
            DIRECT_ABSTRACT_DECLARATOR,
            PARAMETER_DECLARATION_CLAUSE,
            PARAMETER_DECLARATION_LIST,
            PARAMETER_DECLARATION,
            PARAMETER_DECLARATION_DECL_SPECIFIER_SEQ1,
            PARAMETER_DECLARATION_DECL_SPECIFIER_SEQ2,
            PARAMETER_DECLARATION_DECL_SPECIFIER_SEQ3,
            PARAMETER_DECLARATION_DECL_SPECIFIER_SEQ4,
            FUNCTION_DEFINITION,
            FUNCTION_DEFINITION_DECL_SPECIFIER_SEQ1,
            FUNCTION_DEFINITION_DECL_SPECIFIER_SEQ2,
            FUNCTION_DEFINITION_DECL_SPECIFIER_SEQ3,
            FUNCTION_BODY,
            INITIALIZER,
            INITIALIZER_CLAUSE,
            INITIALIZER_LIST,

            CLASS_NAME,
            CLASS_SPECIFIER,
            CLASS_HEAD,
            CLASS_KEY,
            MEMBER_SPECIFICATION,
            MEMBER_DECLARATION,
            MEMBER_DECLARATION_DECL_SPECIFIER_SEQ,
            MEMBER_DECLARATOR_LIST,
            MEMBER_DECLARATOR,
            PURE_SPECIFIER,
            CONSTANT_INITIALIZER,

            BASE_CLAUSE,
            BASE_SPECIFIER_LIST,
            BASE_SPECIFIER,
            ACCESS_SPECIFIER,

            CONVERSION_FUNCTION_ID,
            CONVERSION_TYPE_ID,
            CONVERSION_DECLARATOR,
            CTOR_INITIALIZER,
            MEM_INITIALIZER_LIST,
            MEM_INITIALIZER,
            MEM_INITIALIZER_ID,

            OPERATOR_FUNCTION_ID,
            OPERATOR_,

            TEMPLATE_DECLARATION,
            TEMPLATE_PARAMETER_LIST,
            TEMPLATE_PARAMETER,
            TYPE_PARAMETER,
            TEMPLATE_ID,
            TEMPLATE_NAME,
            TEMPLATE_ARGUMENT_LIST,
            TEMPLATE_ARGUMENT,
            EXPLICIT_INSTANTIATION,
            EXPLICIT_SPECIALIZATION,

            TRY_BLOCK,
            FUNCTION_TRY_BLOCK,
            HANDLER_SEQ,
            HANDLER,
            EXCEPTION_DECLARATION,
            THROW_EXPRESSION,
            EXCEPTION_SPECIFICATION,
            TYPE_ID_LIST,


            SKIP_FUNCTION_BODIES_MODE_STATEMENT_SEQ_ITEM,
            SKIP_FUNCTION_BODIES_MODE_NON_SPECIAL_CHAR_SEQ,
            SKIP_FUNCTION_BODIES_MODE_NON_SPECIAL_CHAR,


            TYPEOF_EXPRESSION,
            TYPEOF_KEYWORD,
            RESTRICT_KEYWORD
        };

        template <typename ScannerT>
        struct definition
        {
            definition(const grammar& self);
            boost::spirit::rule<ScannerT> const& start() const;


            /*
            Chapter numbers refer to ISO/IEC 14882:1998(E) (C++98 Standard), Annex A (grammar summary)
            */

            boost::spirit::rule<ScannerT> file;

            boost::spirit::rule<ScannerT> source_character_set;
            boost::spirit::rule<ScannerT> keyword;

            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<EXPORT_KEYWORD>> export_keyword;

            //1.2 - Lexical conventions [gram.lex]
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> hex_quad;
            boost::spirit::rule<ScannerT> universal_character_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<IDENTIFIER>> identifier;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> nondigit;
            boost::spirit::rule<ScannerT> literal;
            boost::spirit::rule<ScannerT> integer_literal;
            boost::spirit::rule<ScannerT> decimal_literal;
            boost::spirit::rule<ScannerT> octal_literal;
            boost::spirit::rule<ScannerT> hexadecimal_literal;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> hexadecimal_digit;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> octal_digit;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> nonzero_digit;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> integer_suffix;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> unsigned_suffix;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> long_suffix;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> long_long_suffix;
            boost::spirit::rule<ScannerT> character_literal;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> c_char_sequence;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> c_char;
            boost::spirit::rule<ScannerT> escape_sequence;
            boost::spirit::rule<ScannerT> simple_escape_sequence;
            boost::spirit::rule<ScannerT> octal_escape_sequence;
            boost::spirit::rule<ScannerT> hexadecimal_escape_sequence;
            boost::spirit::rule<ScannerT> floating_literal;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> fractional_constant;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> exponent_part;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> digit_sequence;
            boost::spirit::rule<typename boost::spirit::lexeme_scanner<ScannerT>::type> floating_suffix;
            boost::spirit::rule<ScannerT> string_literal;
            boost::spirit::rule<ScannerT> s_char_sequence;
            boost::spirit::rule<ScannerT> s_char;
            boost::spirit::rule<ScannerT> boolean_literal;

            //1.3 - Basic concepts [gram.basic]
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<TRANSLATION_UNIT>> translation_unit;

            //1.4 - Expressions [gram.expr]
            boost::spirit::rule<ScannerT> primary_expression;
            boost::spirit::rule<ScannerT> id_expression;
            boost::spirit::rule<ScannerT> unqualified_id;
            boost::spirit::rule<ScannerT> qualified_id;
            boost::spirit::rule<ScannerT> nested_name_specifier;
            boost::spirit::rule<ScannerT> class_or_namespace_name;
            boost::spirit::rule<ScannerT> postfix_expression;
            boost::spirit::rule<ScannerT> expression_list;
            boost::spirit::rule<ScannerT> pseudo_destructor_name;
            boost::spirit::rule<ScannerT> unary_expression;
            boost::spirit::rule<ScannerT> unary_operator;
            boost::spirit::rule<ScannerT> new_expression;
            boost::spirit::rule<ScannerT> new_placement;
            boost::spirit::rule<ScannerT> new_type_id;
            boost::spirit::rule<ScannerT> new_declarator;
            boost::spirit::rule<ScannerT> direct_new_declarator;
            boost::spirit::rule<ScannerT> new_initializer;
            boost::spirit::rule<ScannerT> delete_expression;
            boost::spirit::rule<ScannerT> cast_expression;
            boost::spirit::rule<ScannerT> pm_expression;
            boost::spirit::rule<ScannerT> multiplicative_expression;
            boost::spirit::rule<ScannerT> additive_expression;
            boost::spirit::rule<ScannerT> shift_expression;
            boost::spirit::rule<ScannerT> template_argument_shift_expression;
            boost::spirit::rule<ScannerT> relational_expression;
            boost::spirit::rule<ScannerT> template_argument_relational_expression;
            boost::spirit::rule<ScannerT> equality_expression;
            boost::spirit::rule<ScannerT> template_argument_equality_expression;
            boost::spirit::rule<ScannerT> and_expression;
            boost::spirit::rule<ScannerT> template_argument_and_expression;
            boost::spirit::rule<ScannerT> exclusive_or_expression;
            boost::spirit::rule<ScannerT> template_argument_exclusive_or_expression;
            boost::spirit::rule<ScannerT> inclusive_or_expression;
            boost::spirit::rule<ScannerT> template_argument_inclusive_or_expression;
            boost::spirit::rule<ScannerT> logical_and_expression;
            boost::spirit::rule<ScannerT> template_argument_logical_and_expression;
            boost::spirit::rule<ScannerT> logical_or_expression;
            boost::spirit::rule<ScannerT> template_argument_logical_or_expression;
            boost::spirit::rule<ScannerT> conditional_expression;
            boost::spirit::rule<ScannerT> template_argument_conditional_expression;
            boost::spirit::rule<ScannerT> assignment_expression;
            boost::spirit::rule<ScannerT> template_argument_assignment_expression;
            boost::spirit::rule<ScannerT> assignment_operator;
            boost::spirit::rule<ScannerT> expression;
            boost::spirit::rule<ScannerT> constant_expression;

            //1.5 - Statements [gram.stmt.stmt]
            boost::spirit::rule<ScannerT> statement;
            boost::spirit::rule<ScannerT> labeled_statement;
            boost::spirit::rule<ScannerT> expression_statement;
            boost::spirit::rule<ScannerT> compound_statement;
            boost::spirit::rule<ScannerT> statement_seq;
            boost::spirit::rule<ScannerT> selection_statement;
            boost::spirit::rule<ScannerT> condition;
            boost::spirit::rule<ScannerT> condition_type_specifier_seq;
            boost::spirit::rule<ScannerT> iteration_statement;
            boost::spirit::rule<ScannerT> for_init_statement;
            boost::spirit::rule<ScannerT> jump_statement;
            boost::spirit::rule<ScannerT> declaration_statement;

            //1.6 - Declarations [gram.dcl.dcl]
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<DECLARATION_SEQ>> declaration_seq;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<DECLARATION>> declaration;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<BLOCK_DECLARATION>> block_declaration;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<SIMPLE_DECLARATION>> simple_declaration;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<SIMPLE_DECLARATION_DECL_SPECIFIER_SEQ>> simple_declaration_decl_specifier_seq;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<DECL_SPECIFIER>> decl_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<DECL_SPECIFIER_SEQ>> decl_specifier_seq;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<STORAGE_CLASS_SPECIFIER>> storage_class_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<FUNCTION_SPECIFIER>> function_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<TYPEDEF_NAME>> typedef_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<TYPE_SPECIFIER>> type_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<SIMPLE_TYPE_SPECIFIER>> simple_type_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<TYPE_NAME>> type_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ELABORATED_TYPE_SPECIFIER>> elaborated_type_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ENUM_NAME>> enum_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ENUM_SPECIFIER>> enum_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ENUMERATOR_LIST>> enumerator_list;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ENUMERATOR_DEFINITION>> enumerator_definition;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ENUMERATOR>> enumerator;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<NAMESPACE_NAME>> namespace_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ORIGINAL_NAMESPACE_NAME>> original_namespace_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<NAMESPACE_DEFINITION>> namespace_definition;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<NAMED_NAMESPACE_DEFINITION>> named_namespace_definition;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<UNNAMED_NAMESPACE_DEFINITION>> unnamed_namespace_definition;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<NAMESPACE_BODY>> namespace_body;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<NAMESPACE_ALIAS>> namespace_alias;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<NAMESPACE_ALIAS_DEFINITION>> namespace_alias_definition;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<QUALIFIED_NAMESPACE_SPECIFIER>> qualified_namespace_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<USING_DECLARATION>> using_declaration;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<USING_DIRECTIVE>> using_directive;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ASM_DEFINITION>> asm_definition;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<LINKAGE_SPECIFICATION>> linkage_specification;

            //1.7 - Declarators [gram.dcl.decl]
            boost::spirit::rule<ScannerT> init_declarator_list;
            boost::spirit::rule<ScannerT> init_declarator;
            boost::spirit::rule<ScannerT> declarator;
            boost::spirit::rule<ScannerT> direct_declarator;
            boost::spirit::rule<ScannerT> ptr_operator;
            boost::spirit::rule<ScannerT> cv_qualifier_seq;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<CV_QUALIFIER>> cv_qualifier;
            boost::spirit::rule<ScannerT> declarator_id;
            boost::spirit::rule<ScannerT> type_id;
            boost::spirit::rule<ScannerT> type_specifier_seq;
            boost::spirit::rule<ScannerT> abstract_declarator;
            boost::spirit::rule<ScannerT> direct_abstract_declarator;
            boost::spirit::rule<ScannerT> parameter_declaration_clause;
            boost::spirit::rule<ScannerT> parameter_declaration_list;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<PARAMETER_DECLARATION>> parameter_declaration;
            boost::spirit::rule<ScannerT> parameter_declaration_decl_specifier_seq1;
            boost::spirit::rule<ScannerT> parameter_declaration_decl_specifier_seq2;
            boost::spirit::rule<ScannerT> parameter_declaration_decl_specifier_seq3;
            boost::spirit::rule<ScannerT> parameter_declaration_decl_specifier_seq4;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<FUNCTION_DEFINITION>> function_definition;
            boost::spirit::rule<ScannerT> function_definition_decl_specifier_seq1;
            boost::spirit::rule<ScannerT> function_definition_decl_specifier_seq2;
            boost::spirit::rule<ScannerT> function_definition_decl_specifier_seq3;
            boost::spirit::rule<ScannerT> function_body;
            boost::spirit::rule<ScannerT> initializer;
            boost::spirit::rule<ScannerT> initializer_clause;
            boost::spirit::rule<ScannerT> initializer_list;

            //1.8 - Classes [gram.class]
            boost::spirit::rule<ScannerT> class_name;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<CLASS_SPECIFIER>> class_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<CLASS_HEAD>> class_head;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<CLASS_KEY>> class_key;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<MEMBER_SPECIFICATION>> member_specification;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<MEMBER_DECLARATION>> member_declaration;
            boost::spirit::rule<ScannerT> member_declaration_decl_specifier_seq;
            boost::spirit::rule<ScannerT> member_declarator_list;
            boost::spirit::rule<ScannerT> member_declarator;
            boost::spirit::rule<ScannerT> pure_specifier;
            boost::spirit::rule<ScannerT> constant_initializer;

            //1.9 - Derived classes [gram.class.derived]
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<BASE_CLAUSE>> base_clause;
            boost::spirit::rule<ScannerT> base_specifier_list;
            boost::spirit::rule<ScannerT> base_specifier;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<ACCESS_SPECIFIER>> access_specifier;

            //1.10 - Special member functions [gram.special]
            boost::spirit::rule<ScannerT> conversion_function_id;
            boost::spirit::rule<ScannerT> conversion_type_id;
            boost::spirit::rule<ScannerT> conversion_declarator;
            boost::spirit::rule<ScannerT> ctor_initializer;
            boost::spirit::rule<ScannerT> mem_initializer_list;
            boost::spirit::rule<ScannerT> mem_initializer;
            boost::spirit::rule<ScannerT> mem_initializer_id;

            //1.11 - Overloading [gram.over]
            boost::spirit::rule<ScannerT> operator_function_id;
            boost::spirit::rule<ScannerT> operator_;

            //1.12 - Templates [gram.temp]
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<TEMPLATE_DECLARATION>> template_declaration;
            boost::spirit::rule<ScannerT> template_parameter_list;
            boost::spirit::rule<ScannerT> template_parameter;
            boost::spirit::rule<ScannerT> type_parameter;
            boost::spirit::rule<ScannerT> template_id;
            boost::spirit::rule<ScannerT> template_name;
            boost::spirit::rule<ScannerT> template_argument_list;
            boost::spirit::rule<ScannerT> template_argument;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<EXPLICIT_INSTANTIATION>> explicit_instantiation;
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<EXPLICIT_SPECIALIZATION>> explicit_specialization;

            //1.13 - Exception handling [gram.except]
            boost::spirit::rule<ScannerT> try_block;
            boost::spirit::rule<ScannerT> function_try_block;
            boost::spirit::rule<ScannerT> handler_seq;
            boost::spirit::rule<ScannerT> handler;
            boost::spirit::rule<ScannerT> exception_declaration;
            boost::spirit::rule<ScannerT> throw_expression;
            boost::spirit::rule<ScannerT> exception_specification;
            boost::spirit::rule<ScannerT> type_id_list;


            /*
            Convenience rules for 'skip function bodies' mode
            */
            boost::spirit::rule<ScannerT> skip_function_bodies_mode_statement_seq_item;
            boost::spirit::rule<ScannerT> skip_function_bodies_mode_non_special_char_seq;
            boost::spirit::rule<ScannerT> skip_function_bodies_mode_non_special_char;


            /*
            Non-standard extensions
            */
            boost::spirit::rule<ScannerT, boost::spirit::parser_context<>, boost::spirit::parser_tag<TYPEOF_EXPRESSION>> typeof_expression;
            boost::spirit::rule<ScannerT> typeof_keyword;
            boost::spirit::rule<ScannerT> restrict_keyword;
        };

    private:
        configuration& m_configuration;
};

template<typename ScannerT>
grammar::definition<ScannerT>::definition(const grammar& self)
{
    using namespace boost::spirit;

    file
        = translation_unit
    ;

    source_character_set
        = no_node_d
        [
            chset_p("a-zA-Z0-9")
            | '_'
            | '{'
            | '}'
            | '['
            | ']'
            | '#'
            | '('
            | ')'
            | '<'
            | '>'
            | '%'
            | ':'
            | ';'
            | '.'
            | '?'
            | '*'
            | '+'
            | '-'
            | '/'
            | '^'
            | '&'
            | '|'
            | '~'
            | '!'
            | '='
            | ','
            | '\\'
            | '"'
            | '\''
            | ' '  //space
            | '\t' //horizontal tab
            | '\v' //vertical tab
            | '\f' //form feed
            | '\n' //new line
        ]
    ;

    /*
    Sorted in inverse alphabetical order to prevent scanner to parse e.g. "do" when scanning "double"
    Longest to shortest order would have been right too.
    */
    keyword
        = no_node_d
        [
            str_p("xor_eq")
            | "xor"
            | "while"
            | "wchar_t"
            | "volatile"
            | "void"
            | "virtual"
            | "using"
            | "unsigned"
            | "union"
            | typeof_keyword
            | "typename"
            | "typeid"
            | "typedef"
            | "try"
            | "true"
            | "throw"
            | "this"
            | "template"
            | "switch"
            | "struct"
            | "static_cast"
            | "static"
            | "sizeof"
            | "signed"
            | "short"
            | "return"
            | restrict_keyword
            | "reinterpret_cast"
            | "register"
            | "public"
            | "protected"
            | "private"
            | "or_eq"
            | "or"
            | "operator"
            | "not_eq"
            | "not"
            | "new"
            | "namespace"
            | "mutable"
            | "long"
            | "int"
            | "inline"
            | "if"
            | "goto"
            | "friend"
            | "for"
            | "float"
            | "false"
            | "extern"
            | "export"
            | "explicit"
            | "enum"
            | "else"
            | "dynamic_cast"
            | "double"
            | "do"
            | "delete"
            | "default"
            | "continue"
            | "const_cast"
            | "const"
            | "compl"
            | "class"
            | "char"
            | "catch"
            | "case"
            | "break"
            | "bool"
            | "bitor"
            | "bitand"
            | "auto"
            | "asm"
            | "and_eq"
            | "and"
        ]
    ;

    export_keyword
        = no_node_d[str_p("export")]
    ;


    //1.2 - Lexical conventions [gram.lex]
    hex_quad
        = hexadecimal_digit >> hexadecimal_digit >> hexadecimal_digit >> hexadecimal_digit
    ;

    universal_character_name
        = lexeme_d[str_p("\\u") >> hex_quad]
        | lexeme_d[str_p("\\U") >> hex_quad >> hex_quad]
    ;

    identifier
        = token_node_d
        [
            (nondigit >> *(nondigit | digit_p)) - keyword
        ]
    ;

    nondigit
        = no_node_d
        [
            universal_character_name
            | chset_p("a-zA-Z")
            | '_'
        ]
    ;

    literal
        = boolean_literal
        | character_literal
        | string_literal
        | floating_literal
        | integer_literal
    ;

    integer_literal
        = lexeme_d[decimal_literal >> !integer_suffix]
        | lexeme_d[hexadecimal_literal >> !integer_suffix]
        | lexeme_d[octal_literal >> !integer_suffix]
    ;

    decimal_literal
        = lexeme_d[nonzero_digit >> *digit_p]
    ;

    octal_literal
        = lexeme_d['0' >> *octal_digit]
    ;

    hexadecimal_literal
        = lexeme_d[(str_p("0x") | "0X") >> +hexadecimal_digit]
    ;

    hexadecimal_digit
        = chset_p("0-9a-fA-F")
    ;

    octal_digit
        = chset_p("0-7")
    ;

    nonzero_digit
        = chset_p("1-9")
    ;

    integer_suffix
        = unsigned_suffix >> !(long_long_suffix | long_suffix)
        | (long_long_suffix | long_suffix) >> !unsigned_suffix
    ;

    unsigned_suffix
        = ch_p('u') | 'U'
    ;

    long_suffix
        = ch_p('l') | 'L'
    ;

    long_long_suffix
        = str_p("ll") | "LL"
    ;

    character_literal
        = lexeme_d['\'' >> c_char_sequence >> '\'']
        | lexeme_d["L\'" >> c_char_sequence >> '\'']
    ;

    c_char_sequence
        = +c_char
    ;

    c_char
        = (source_character_set & ~ch_p('\'') & ~ch_p('\\') & ~ch_p('\n'))
        | escape_sequence
        | universal_character_name
    ;

    escape_sequence
        = simple_escape_sequence
        | octal_escape_sequence
        | hexadecimal_escape_sequence
    ;

    simple_escape_sequence
        = str_p("\\'")
        | "\\\""
        | "\\?"
        | "\\\\"
        | "\\a"
        | "\\b"
        | "\\f"
        | "\\n"
        | "\\r"
        | "\\t"
        | "\\v"
    ;

    octal_escape_sequence
        = lexeme_d['\\' >> octal_digit >> !octal_digit >> !octal_digit]
    ;

    hexadecimal_escape_sequence
        = lexeme_d["\\x" >> +hexadecimal_digit]
    ;

    floating_literal
        = lexeme_d[fractional_constant >> !exponent_part >> !floating_suffix]
        | lexeme_d[digit_sequence >> exponent_part >> !floating_suffix]
    ;

    fractional_constant
        = !digit_sequence >> '.' >> digit_sequence
        | digit_sequence >> '.'
    ;

    exponent_part
        = ch_p('e') >> !sign_p >> digit_sequence
        | ch_p('E') >> !sign_p >> digit_sequence
    ;

    digit_sequence
        = +digit_p
    ;

    floating_suffix
        = ch_p('f')
        | 'l'
        | 'F'
        | 'L'
    ;

    string_literal
        = +('"' >> !s_char_sequence >> '"')
        | +("L\"" >> !s_char_sequence >> '"')
    ;

    s_char_sequence
        = +s_char
    ;

    s_char
        = (source_character_set & ~ch_p('"') & ~ch_p('\\') & ~ch_p('\n'))
        | escape_sequence
        | universal_character_name
    ;

    boolean_literal
        = str_p("false")
        | "true"
    ;

    //1.3 - Basic concepts [gram.basic]
    translation_unit
        = !declaration_seq >> end_p
    ;

    //1.4 - Expressions [gram.expr]
    primary_expression
        = "this"
        | literal
        | '(' >> expression >> ')'
        | id_expression
    ;

    id_expression
        = qualified_id
        | unqualified_id
    ;

    unqualified_id
        = operator_function_id
        | conversion_function_id
        | '~' >> class_name
        | template_id
        | identifier
    ;

    qualified_id
        = !str_p("::") >> nested_name_specifier >> !str_p("template") >> unqualified_id
        | str_p("::") >> operator_function_id
        | str_p("::") >> template_id
        | str_p("::") >> identifier
    ;

    nested_name_specifier
        = class_or_namespace_name >> str_p("::") >> "template" >> nested_name_specifier
        | class_or_namespace_name >> str_p("::") >> !nested_name_specifier
    ;

    class_or_namespace_name
        = class_name
        | namespace_name
    ;

    /*
    The following rule is written like this in the standard:
        postfix_expression
            = primary_expression
            | postfix_expression >> '[' >> expression >> ']'
            | postfix_expression >> '(' >> !expression_list >> ')'
            | simple_type_specifier >> '(' >> !expression_list >> ')'
            | str_p("typename") >> !str_p("::") >> nested_name_specifier >> identifier >> '(' >> !expression_list >> ')'
            | str_p("typename") >> !str_p("::") >> nested_name_specifier >> !str_p("template") >> template_id >> '(' >> !expression_list >> ')'
            | postfix_expression >> '.' >> !str_p("template") >> id_expression
            | postfix_expression >> "->" >> !str_p("template") >> id_expression
            | postfix_expression >> '.' >> pseudo_destructor_name
            | postfix_expression >> "->" >> pseudo_destructor_name
            | postfix_expression >> "++"
            | postfix_expression >> "--"
            | str_p("dynamic_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("static_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("reinterpret_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("const_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("typeid") >> '(' >> expression >> ')'
            | str_p("typeid") >> '(' >> type_id >> ')'
        ;
    There are some left recursions that we had to eliminate.
    See direct_declarator rule for more information about the different steps to follow.
    */
    postfix_expression
        =
        (
            primary_expression
            | simple_type_specifier >> '(' >> !expression_list >> ')'
            | str_p("typename") >> !str_p("::") >> nested_name_specifier >> identifier >> '(' >> !expression_list >> ')'
            | str_p("typename") >> !str_p("::") >> nested_name_specifier >> !str_p("template") >> template_id >> '(' >> !expression_list >> ')'
            | str_p("dynamic_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("static_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("reinterpret_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("const_cast") >> '<' >> type_id >> '>' >> '(' >> expression >> ')'
            | str_p("typeid") >> '(' >> expression >> ')'
            | str_p("typeid") >> '(' >> type_id >> ')'
        )
        >>
        *(
            '[' >> expression >> ']'
            | '(' >> !expression_list >> ')'
            | '.' >> !str_p("template") >> id_expression
            | "->" >> !str_p("template") >> id_expression
            | '.' >> pseudo_destructor_name
            | "->" >> pseudo_destructor_name
            | "++"
            | "--"
        )
    ;

    expression_list
        = assignment_expression % ','
    ;

    pseudo_destructor_name
        = !str_p("::") >> !nested_name_specifier >> type_name >> str_p("::") >> '~' >> type_name
        | !str_p("::") >> nested_name_specifier >> str_p("template") >> template_id >> str_p("::") >> '~' >> type_name
        | !str_p("::") >> !nested_name_specifier >> '~' >> type_name
    ;

    unary_expression
        = "++" >> cast_expression
        | "--" >> cast_expression
        | unary_operator >> cast_expression
        | str_p("sizeof") >> '(' >> type_id >> ')'
        | str_p("sizeof") >> unary_expression
        | postfix_expression
        | new_expression
        | delete_expression
    ;

    unary_operator
        = ch_p('*')
        | '&'
        | '+'
        | '-'
        | '!'
        | '~'
    ;

    new_expression
        = !str_p("::") >> str_p("new") >> !new_placement >> '(' >> type_id >> ')' >> !new_initializer
        | !str_p("::") >> str_p("new") >> !new_placement >> new_type_id >> !new_initializer
    ;

    new_placement
        = '(' >> expression_list >> ')'
    ;

    new_type_id
        = type_specifier_seq >> !new_declarator
    ;

    new_declarator
        = ptr_operator >> !new_declarator
        | direct_new_declarator
    ;

    direct_new_declarator
        = '[' >> expression >> ']' >> !('[' >> constant_expression >> ']')
    ;

    new_initializer
        = '(' >> !expression_list >> ')'
    ;

    delete_expression
        = !str_p("::") >> "delete" >> '[' >> ']' >> cast_expression
        | !str_p("::") >> "delete" >> cast_expression
    ;

    cast_expression
        = '(' >> type_id >> ')' >> cast_expression
        | unary_expression
    ;

    pm_expression
        = cast_expression % (str_p(".*") | "->*")
    ;

    multiplicative_expression
        = pm_expression % (ch_p('*') | '/' | '%')
    ;

    additive_expression
        = multiplicative_expression % (ch_p('+') | '-')
    ;

    shift_expression
        = additive_expression % (str_p("<<") | ">>")
    ;
    //a shift expression used as a template argument must be placed between braces if it contains any '>' characters
    template_argument_shift_expression
        = '(' >> (additive_expression % (str_p("<<") | ">>")) >> ')'
        | additive_expression % str_p("<<")
    ;

    relational_expression
        = shift_expression % (str_p("<=") | ">=" | '<' | '>')
    ;
    //a relational_expression used as a template argument must be placed between braces if it contains any '>' characters
    template_argument_relational_expression
        = '(' >> (shift_expression % (str_p("<=") | ">=" | '<' | '>')) >> ')'
        | template_argument_shift_expression % (str_p("<=") | '<')
    ;

    equality_expression
        = relational_expression % (str_p("==") | "!=")
    ;
    template_argument_equality_expression
        = template_argument_relational_expression % (str_p("==") | "!=")
    ;

    and_expression
        = equality_expression % '&'
    ;
    template_argument_and_expression
        = template_argument_equality_expression % '&'
    ;

    exclusive_or_expression
        = and_expression % '^'
    ;
    template_argument_exclusive_or_expression
        = template_argument_and_expression % '^'
    ;

    inclusive_or_expression
        = exclusive_or_expression % '|'
    ;
    template_argument_inclusive_or_expression
        = template_argument_exclusive_or_expression % '|'
    ;

    logical_and_expression
        = inclusive_or_expression % "&&"
    ;
    template_argument_logical_and_expression
        = template_argument_inclusive_or_expression % "&&"
    ;

    logical_or_expression
        = logical_and_expression % "||"
    ;
    template_argument_logical_or_expression
        = template_argument_logical_and_expression % "||"
    ;

    conditional_expression
        = logical_or_expression >> !('?' >> expression >> ':' >> assignment_expression)
    ;
    template_argument_conditional_expression
        = template_argument_logical_or_expression >> !('?' >> expression >> ':' >> template_argument_assignment_expression)
    ;

    assignment_expression
        = logical_or_expression >> assignment_operator >> assignment_expression
        | conditional_expression
        | throw_expression
    ;
    template_argument_assignment_expression
        = template_argument_logical_or_expression >> assignment_operator >> template_argument_assignment_expression
        | template_argument_conditional_expression
        | throw_expression
    ;

    assignment_operator
        = str_p("=")
        | "*="
        | "/="
        | "%="
        | "+="
        | "-="
        | ">>="
        | "<<="
        | "&="
        | "^="
        | "|="
    ;

    expression
        = assignment_expression % ','
    ;

    constant_expression
        = conditional_expression
    ;

    //1.5 - Statements [gram.stmt.stmt]
    statement
        = labeled_statement
        | expression_statement
        | compound_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        | declaration_statement
        | try_block
    ;

    labeled_statement
        = str_p("case") >> constant_expression >> ':' >> statement
        | str_p("default") >> ':' >> statement
        | identifier >> ':' >> statement
    ;

    expression_statement
        = !expression >> ch_p(';')
    ;

    compound_statement
        = ch_p('{') >> !statement_seq >> ch_p('}')
    ;

    if(self.m_configuration.skip_function_bodies)
    {
        statement_seq
            = +skip_function_bodies_mode_statement_seq_item
        ;
        skip_function_bodies_mode_statement_seq_item
            = token_node_d
            [
                character_literal
                | string_literal
                | compound_statement
                | skip_function_bodies_mode_non_special_char_seq
            ]
        ;
    }
    else
    {
        statement_seq
            = +statement
        ;
    }

    selection_statement
        = str_p("if") >> '(' >> condition >> ')' >> statement >> !("else" >> statement)
        | str_p("switch") >> '(' >> condition >> ')' >> statement
    ;

    /*
    Original rule is:
        condition
            = expression
            | type_specifier_seq >> declarator >> '=' >> assignment_expression
        ;
    */
    condition
        = expression
        | condition_type_specifier_seq >> declarator >> '=' >> assignment_expression
    ;
    condition_type_specifier_seq
        = +(type_specifier - (declarator >> '=' >> assignment_expression))
    ;

    iteration_statement
        = str_p("while") >> '(' >> condition >> ')' >> statement
        | str_p("do") >> statement >> "while" >> '(' >> expression >> ')' >> ch_p(';')
        | str_p("for") >> '(' >> for_init_statement >> !condition >> ch_p(';') >> !expression >> ')' >> statement
    ;

    for_init_statement
        = expression_statement
        | simple_declaration
    ;

    jump_statement
        = str_p("break") >> ch_p(';')
        | str_p("continue") >> ch_p(';')
        | str_p("return") >> !expression >> ch_p(';')
        | str_p("goto") >> identifier >> ch_p(';')
    ;

    declaration_statement
        = block_declaration
    ;

    //1.6 - Declarations [gram.dcl.dcl]
    declaration_seq
        = +declaration
    ;

    declaration
        = block_declaration
        | function_definition
        | template_declaration
        | explicit_instantiation
        | explicit_specialization
        | linkage_specification
        | namespace_definition
    ;

    block_declaration
        = asm_definition
        | simple_declaration
        | namespace_alias_definition
        | using_declaration
        | using_directive
    ;

    /*
    The following rule is written like this in the standard:
        simple_declaration
            = !decl_specifier_seq >> !init_declarator_list >> ch_p(';')
        ;
    If we wrote it that way, with such an input:
        int i, j;
    The scanner will parse "i" as a decl_specifier (it is indeed a correct type_name).
    Consequently, when it will try to parse the comma, it will raise an error.

    In order to solve this issue, we have to create an extra rule which specifies a tail parser.
    */
    ///@todo semantic disambiguation between decl_specifier and init_declarator_list
    simple_declaration
        = !simple_declaration_decl_specifier_seq >> !init_declarator_list >> ch_p(';')
    ;
    simple_declaration_decl_specifier_seq
        = +(decl_specifier - (init_declarator_list >> ch_p(';')))
    ;

    decl_specifier
        = storage_class_specifier
        | type_specifier
        | function_specifier
        | str_p("friend")
        | str_p("typedef")
    ;

    decl_specifier_seq
        = +decl_specifier
    ;

    storage_class_specifier
        = str_p("auto")
        | str_p("register")
        | str_p("static")
        | str_p("extern")
        | str_p("mutable")
    ;

    function_specifier
        = str_p("inline")
        | "virtual"
        | "explicit"
    ;

    typedef_name
        = identifier
    ;

    type_specifier
        = simple_type_specifier
        | class_specifier
        | enum_specifier
        | elaborated_type_specifier
        | cv_qualifier
        | typeof_expression
    ;

    simple_type_specifier
        = !str_p("::") >> !nested_name_specifier >> type_name
        | !str_p("::") >> nested_name_specifier >> "template" >> template_id
        | str_p("char")
        | "wchar_t"
        | "bool"
        | "short"
        | "int"
        | "long"
        | "signed"
        | "unsigned"
        | "float"
        | "double"
        | "void"
    ;

    type_name
        = class_name
        | enum_name
        | typedef_name
    ;

    elaborated_type_specifier
        = class_key >> !str_p("::") >> !nested_name_specifier >> template_id //not in the standard, but seems to be required for parsing standard library
        | class_key >> !str_p("::") >> !nested_name_specifier >> identifier
        | str_p("enum") >> !str_p("::") >> !nested_name_specifier >> identifier
        | str_p("typename") >> !str_p("::") >> nested_name_specifier >> !str_p("template") >> template_id
        | str_p("typename") >> !str_p("::") >> nested_name_specifier >> identifier
    ;

    enum_name
        = identifier
    ;

    enum_specifier
        = str_p("enum") >> !identifier >> ch_p('{') >> !enumerator_list >> ch_p('}')
    ;

    enumerator_list
        = enumerator_definition % ','
    ;

    enumerator_definition
        = enumerator >> !('=' >> constant_expression)
    ;

    enumerator
        = identifier
    ;

    namespace_name
        = original_namespace_name
        | namespace_alias
    ;

    original_namespace_name
        = identifier
    ;

    namespace_definition
        = named_namespace_definition
        | unnamed_namespace_definition
    ;

    named_namespace_definition
        = str_p("namespace") >> identifier >> '{' >> namespace_body >> '}'
    ;

    unnamed_namespace_definition
        = str_p("namespace") >> '{' >> namespace_body >> '}'
    ;

    namespace_body
        = !declaration_seq
    ;

    namespace_alias
        = identifier
    ;

    namespace_alias_definition
        = str_p("namespace") >> identifier >> '=' >> qualified_namespace_specifier >> ch_p(';')
    ;

    qualified_namespace_specifier
        = !str_p("::") >> !nested_name_specifier >> namespace_name
    ;

    using_declaration
        = "using" >> !str_p("typename") >> !str_p("::") >> nested_name_specifier >> unqualified_id >> ch_p(';')
        | "using" >> str_p("::") >> unqualified_id >> ch_p(';')
    ;

    using_directive
        = str_p("using") >> "namespace" >> !str_p("::") >> !nested_name_specifier >> namespace_name >> ch_p(';')
    ;

    asm_definition
        = str_p("asm") >> '(' >> string_literal >> ')' >> ch_p(';')
    ;

    linkage_specification
        = "extern" >> string_literal >> ch_p('{') >> !declaration_seq >> ch_p('}')
        | "extern" >> string_literal >> declaration
    ;

    //1.7 - Declarators [gram.dcl.decl]
    init_declarator_list
        = init_declarator % ','
    ;

    init_declarator
        = declarator >> !initializer
    ;

    declarator
        = ptr_operator >> declarator
        | direct_declarator
    ;

    /*
    Original rule is:
        direct_declarator
            = declarator_id
            | direct_declarator >> '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
            | direct_declarator >> '[' >> !constant_expression >> ']'
            | '(' >> declarator >> ')'
        ;

    We have to eliminate left recursion. There are the different steps on this elimination:

        direct_declarator
            = declarator_id
            | '(' >> declarator >> ')'
            | direct_declarator >> direct_declarator_rest
        ;
        direct_declarator_rest
            = '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
            | '[' >> !constant_expression >> ']'
        ;

        ***

        direct_declarator
            = (declarator_id | '(' >> declarator >> ')') >> direct_declarator_rest

        ;
        direct_declarator_rest
            = '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification >> direct_declarator_rest
            | '[' >> !constant_expression >> ']' >> direct_declarator_rest
            | epsilon_p
        ;

        ***

        direct_declarator
            = (declarator_id | '(' >> declarator >> ')') >> direct_declarator_rest
        ;
        direct_declarator_rest
            =
                (
                    '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
                    | '[' >> !constant_expression >> ']'
                ) >> direct_declarator_rest
            | epsilon_p
        ;

        ***

        direct_declarator
            = (declarator_id | '(' >> declarator >> ')') >> direct_declarator_rest
        ;
        direct_declarator_rest
            =
                !(
                    (
                        '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
                        | '[' >> !constant_expression >> ']'
                    )
                    >> direct_declarator_rest
                )
        ;

        ***

        direct_declarator
            = (declarator_id | '(' >> declarator >> ')') >> direct_declarator_rest
        ;
        direct_declarator_rest
            =
                *(

                    '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
                    | '[' >> !constant_expression >> ']'
                )
        ;
    */
    direct_declarator
        =
        (
            declarator_id
            | '(' >> declarator >> ')'
        )
        >>
        *(
            '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
            | '[' >> !constant_expression >> ']'
        )
    ;

    ptr_operator
        = ch_p('*') >> !cv_qualifier_seq
        | ch_p('&')
        | !str_p("::") >> nested_name_specifier >> '*' >> !cv_qualifier_seq
    ;

    cv_qualifier_seq
        = +cv_qualifier
    ;

    cv_qualifier
        = str_p("const")
        | "volatile"
        | lexeme_d[!str_p("__") >> "restrict" >> !str_p("__")]
    ;

    declarator_id
        = id_expression
        | !str_p("::") >> !nested_name_specifier >> type_name
    ;

    type_id
        = type_specifier_seq >> !abstract_declarator
    ;

    type_specifier_seq
        = +type_specifier
    ;

    abstract_declarator
        = +ptr_operator
        | direct_abstract_declarator
    ;

    /*
    Original rule is:
        direct_abstract_declarator
            = !direct_abstract_declarator >> '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
            | !direct_abstract_declarator >> '[' >> !constant_expression >> ']'
            | '(' >> abstract_declarator >> ')'
        ;
    */
    direct_abstract_declarator
        =
        !(
            '(' >> abstract_declarator >> ')'
        )
        >>
        *(
            '(' >> parameter_declaration_clause >> ')' >> !cv_qualifier_seq >> !exception_specification
            | '[' >> !constant_expression >> ']'
        )
    ;

    parameter_declaration_clause
        = parameter_declaration_list >> ',' >> "..."
        | !parameter_declaration_list >> !str_p("...")
    ;

    parameter_declaration_list
        = parameter_declaration % ','
    ;

    parameter_declaration
        = parameter_declaration_decl_specifier_seq1 >> declarator >> '=' >> assignment_expression
        | parameter_declaration_decl_specifier_seq2 >> declarator
        | parameter_declaration_decl_specifier_seq3 >> abstract_declarator >> '=' >> assignment_expression
        | parameter_declaration_decl_specifier_seq4 >> !abstract_declarator
        | decl_specifier_seq >> '=' >> assignment_expression
    ;
    parameter_declaration_decl_specifier_seq1
        = +(decl_specifier - (declarator >> '=' >> assignment_expression))
    ;
    parameter_declaration_decl_specifier_seq2
        = +(decl_specifier - (declarator >> (ch_p(',') >> ')' >> "...")))
    ;
    parameter_declaration_decl_specifier_seq3
        = +(decl_specifier - (abstract_declarator >> '=' >> assignment_expression))
    ;
    parameter_declaration_decl_specifier_seq4
        = +(decl_specifier - (abstract_declarator >> (ch_p(',') >> ')' >> "...")))
    ;


    /*
    Original rule is:
        function_definition
            = !decl_specifier_seq >> declarator >> !ctor_initializer >> function_body
            | !decl_specifier_seq >> declarator >> function_try_block
        ;
    */
    function_definition
        = !function_definition_decl_specifier_seq1 >> declarator >> ctor_initializer >> function_body
        | !function_definition_decl_specifier_seq2 >> declarator >> function_body
        | !function_definition_decl_specifier_seq3 >> declarator >> function_try_block
    ;
    function_definition_decl_specifier_seq1
        = +(decl_specifier - (declarator >> ctor_initializer >> function_body))
    ;
    function_definition_decl_specifier_seq2
        = +(decl_specifier - (declarator >> function_body))
    ;
    function_definition_decl_specifier_seq3
        = +(decl_specifier - (declarator >> function_try_block))
    ;

    function_body
        = compound_statement
    ;

    initializer
        = ch_p('=') >> initializer_clause
        | ch_p('(') >> expression_list >> ')'
    ;

    initializer_clause
        = assignment_expression
        | ch_p('{') >> initializer_list >> !ch_p(',') >> ch_p('}')
        | ch_p('{') >> ch_p('}')
    ;

    initializer_list
        = initializer_clause % ','
    ;

    //1.8 - Classes [gram.class]
    class_name
        = token_node_d
        [
            template_id
            | identifier
        ]
    ;

    class_specifier
        = class_head >> ch_p('{') >> !member_specification >> ch_p('}')
    ;

    class_head
        = class_key >> !nested_name_specifier >> template_id >> !base_clause //in that case, a forward declaration has already been done
        | class_key >> nested_name_specifier >> identifier >> !base_clause //ditto
        | class_key >> !identifier >> !base_clause
    ;

    class_key
        = token_node_d
        [
            str_p("class")
            | "struct"
            | "union"
        ]
    ;

    member_specification
        = member_declaration >> !member_specification
        | access_specifier >> ':' >> !member_specification
    ;

    member_declaration
        = !member_declaration_decl_specifier_seq >> !member_declarator_list >> ch_p(';')
        | !str_p("::") >> nested_name_specifier >> !str_p("template") >> unqualified_id >> ch_p(';')
        | function_definition >> !ch_p(';')
        | using_declaration
        | template_declaration
    ;
    member_declaration_decl_specifier_seq
        = +(decl_specifier - (member_declarator_list >> ch_p(';')))
    ;

    member_declarator_list
        = member_declarator % ','
    ;

    member_declarator
        = declarator >> !(pure_specifier | constant_initializer) ///@todo find what declarator >> constant_initializer stands for
        | !identifier >> ':' >> constant_expression //bit field member
    ;

    pure_specifier
        = ch_p('=') >> '0'
    ;

    constant_initializer
        = '=' >> constant_expression
    ;

    //1.9 - Derived classes [gram.class.derived]
    base_clause
        = ':' >> base_specifier_list
    ;

    base_specifier_list
        = base_specifier % ','
    ;

    base_specifier
        = !str_p("::") >> !nested_name_specifier >> class_name
        | "virtual" >> !access_specifier >> !str_p("::") >> !nested_name_specifier >> class_name
        | access_specifier >> !str_p("virtual") >> !str_p("::") >> !nested_name_specifier >> class_name
    ;

    access_specifier
        = token_node_d
        [
            str_p("private")
            | "protected"
            | "public"
        ]
    ;

    //1.10 - Special member functions [gram.special]
    conversion_function_id
        = str_p("operator") >> conversion_type_id
    ;

    conversion_type_id
        = type_specifier_seq >> !conversion_declarator
    ;

    conversion_declarator
        = +ptr_operator
    ;

    ctor_initializer
        = ':' >> mem_initializer_list
    ;

    mem_initializer_list
        = mem_initializer % ','
    ;

    mem_initializer
        = mem_initializer_id >> '(' >> !expression_list >> ')'
    ;

    mem_initializer_id
        = !str_p("::") >> !nested_name_specifier >> class_name
        | identifier
    ;

    //1.11 - Overloading [gram.over]
    operator_function_id
        = str_p("operator") >> operator_
    ;

    operator_
        = str_p("new[]")
        | "delete[]"
        | "new"
        | "delete"
        | ">>="
        | "<<="
        | "->*"
        | "+="
        | "-="
        | "*="
        | "/="
        | "%="
        | "^="
        | "&="
        | "|="
        | "<<"
        | ">>"
        | "=="
        | "!="
        | "<="
        | ">="
        | "&&"
        | "||"
        | "++"
        | "--"
        | "->"
        | "()"
        | "[]"
        | ","
        | "+"
        | "-"
        | "*"
        | "/"
        | "%"
        | "^"
        | "&"
        | "|"
        | "~"
        | "!"
        | "="
        | "<"
        | ">"
    ;

    //1.12 - Templates [gram.temp]
    template_declaration
        = !export_keyword >> str_p("template") >> '<' >> template_parameter_list >> '>' >> declaration
    ;

    template_parameter_list
        = template_parameter % ','
    ;

    template_parameter
        = type_parameter
        | parameter_declaration
    ;

    type_parameter
        = str_p("class") >> !identifier >> '=' >> type_id
        | str_p("class") >> !identifier
        | str_p("typename") >> !identifier >> '=' >> type_id
        | str_p("typename") >> !identifier
        | str_p("template") >> '<' >> template_parameter_list >> '>' >> str_p("class") >> !identifier >> '=' >> id_expression
        | str_p("template") >> '<' >> template_parameter_list >> '>' >> str_p("class") >> !identifier
    ;

    template_id
        = template_name >> '<' >> !template_argument_list >> '>'
    ;

    template_name
        = identifier
    ;

    template_argument_list
        = template_argument % ','
    ;

    template_argument
        = longest_d
        [
            template_argument_assignment_expression //As assignment_expression can contain a '>', we cannot use it directly
            | type_id
            | id_expression
        ]
    ;

    explicit_instantiation
        = !str_p("extern") >> str_p("template") >> declaration
    ;

    explicit_specialization
        = str_p("template") >> '<' >> '>' >> declaration
    ;

    //1.13 - Exception handling [gram.except]
    try_block
        = str_p("try") >> compound_statement >> handler_seq
    ;

    function_try_block
        = str_p("try") >> !ctor_initializer >> function_body >> handler_seq
    ;

    handler_seq
        = +handler
    ;

    handler
        = str_p("catch") >> '(' >> exception_declaration >> ')' >> compound_statement
    ;

    exception_declaration
        = type_specifier_seq >> declarator
        | type_specifier_seq >> abstract_declarator
        | type_specifier_seq
        | "..."
    ;

    throw_expression
        = "throw" >> !assignment_expression
    ;

    exception_specification
        = str_p("throw") >> '(' >> !type_id_list >> ')'
    ;

    type_id_list
        = type_id % ','
    ;


    /*
    Convenience rules for declaration-only mode
    */
    skip_function_bodies_mode_non_special_char_seq
        = +skip_function_bodies_mode_non_special_char
    ;
    skip_function_bodies_mode_non_special_char
        = anychar_p - (ch_p('"') | '\'' | '{' | '}')
    ;


    /*
    Extensions
    These rules are not in the standard, but are required to parse some standard library implementations
    */
    if(self.m_configuration.enable_typeof_support)
    {
        typeof_expression
            = typeof_keyword >> '(' >> expression >> ')'
        ;

        typeof_keyword
            = str_p("__typeof__")
            | "__typeof"
            | "typeof"
        ;
    }

    if(self.m_configuration.enable_typeof_support)
    {
        restrict_keyword
            = str_p("__restrict__")
            | "__restrict"
            | "restrict"
        ;
    }
}

template<typename ScannerT>
boost::spirit::rule<ScannerT> const&
grammar::definition<ScannerT>::start() const
{
    return file;
}

} //namespace cppparser

#endif
