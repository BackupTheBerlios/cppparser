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

#ifndef SOCOA_CPP_SYNTAX_NODES_EXPRESSIONS_HPP
#define SOCOA_CPP_SYNTAX_NODES_EXPRESSIONS_HPP

#include "sequence_node.hpp"
#include "common_nodes.hpp"
#include "cast_expression.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

typedef sequence_node<cast_expression, global_nodes::arrow_and_asterisk> pm_ptr_expression;
typedef sequence_node<pm_ptr_expression, global_nodes::dot_and_asterisk> pm_ref_expression;
typedef sequence_node<pm_ref_expression, global_nodes::percent> modulo_expression;
typedef sequence_node<modulo_expression, global_nodes::slash> divisive_expression;
typedef sequence_node<divisive_expression, global_nodes::asterisk> multiplicative_expression;
typedef sequence_node<multiplicative_expression, global_nodes::minus> subtractive_expression;
typedef sequence_node<subtractive_expression, global_nodes::plus> additive_expression;
typedef sequence_node<additive_expression, global_nodes::double_left_angle_bracket> left_shift_expression;
typedef sequence_node<left_shift_expression, global_nodes::double_right_angle_bracket> right_shift_expression;
typedef sequence_node<right_shift_expression, global_nodes::left_angle_bracket_and_equal> less_than_or_equal_to_expression;
typedef sequence_node<less_than_or_equal_to_expression, global_nodes::left_angle_bracket> less_than_expression;
typedef sequence_node<less_than_expression, global_nodes::right_angle_bracket_and_equal> greater_than_or_equal_to_expression;
typedef sequence_node<greater_than_or_equal_to_expression, global_nodes::right_angle_bracket> greater_than_expression;
typedef sequence_node<greater_than_expression, global_nodes::inequal> inequality_expression;
typedef sequence_node<inequality_expression, global_nodes::double_equal> equality_expression;
typedef sequence_node<equality_expression, global_nodes::ampersand> and_expression;
typedef sequence_node<and_expression, global_nodes::circumflex> exclusive_or_expression;
typedef sequence_node<exclusive_or_expression, global_nodes::pipe> inclusive_or_expression;
typedef sequence_node<inclusive_or_expression, global_nodes::double_ampersand> logical_and_expression;
typedef sequence_node<logical_and_expression, global_nodes::double_pipe> logical_or_expression;

}}} //namespace socoa::cpp::syntax_nodes

#endif
