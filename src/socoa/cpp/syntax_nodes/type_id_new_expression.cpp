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

#include "type_id_new_expression.hpp"

#include "common_nodes.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

type_id_new_expression::type_id_new_expression
(
	bool leading_double_colon,
	boost::optional<space>&& post_double_colon_space_node,
	boost::optional<space>&& post_new_keyword_space_node,
	boost::optional<new_placement>&& new_placement_node,
	boost::optional<space>&& post_new_placement_space_node,
	boost::optional<space>&& post_opening_bracket_space_node,
	type_id&& type_id_node,
	boost::optional<space>&& post_type_id_space_node,
	boost::optional<space>&& pre_new_initializer_space_node,
	boost::optional<new_initializer>&& new_initializer_node
):
	leading_double_colon_(leading_double_colon),
	post_double_colon_space_(post_double_colon_space_node),
	post_new_keyword_space_(post_new_keyword_space_node),
	new_placement_(new_placement_node),
	post_new_placement_space_(post_new_placement_space_node),
	post_opening_bracket_space_(post_opening_bracket_space_node),
	type_id_(type_id_node),
	post_type_id_space_(post_type_id_space_node),
	pre_new_initializer_space_(pre_new_initializer_space_node),
	new_initializer_(new_initializer_node)
{
	update_node_list();
}

type_id_new_expression::type_id_new_expression(const type_id_new_expression& o):
	composite_node(),
	leading_double_colon_(o.leading_double_colon_),
	post_double_colon_space_(o.post_double_colon_space_),
	post_new_keyword_space_(o.post_new_keyword_space_),
	new_placement_(o.new_placement_),
	post_new_placement_space_(o.post_new_placement_space_),
	post_opening_bracket_space_(o.post_opening_bracket_space_),
	type_id_(o.type_id_),
	post_type_id_space_(o.post_type_id_space_),
	pre_new_initializer_space_(o.pre_new_initializer_space_),
	new_initializer_(o.new_initializer_)
{
	update_node_list();
}

type_id_new_expression::type_id_new_expression(type_id_new_expression&& o):
	composite_node(),
	leading_double_colon_(o.leading_double_colon_),
	post_double_colon_space_(std::move(o.post_double_colon_space_)),
	post_new_keyword_space_(std::move(o.post_new_keyword_space_)),
	new_placement_(std::move(o.new_placement_)),
	post_new_placement_space_(std::move(o.post_new_placement_space_)),
	post_opening_bracket_space_(std::move(o.post_opening_bracket_space_)),
	type_id_(std::move(o.type_id_)),
	post_type_id_space_(std::move(o.post_type_id_space_)),
	pre_new_initializer_space_(std::move(o.pre_new_initializer_space_)),
	new_initializer_(std::move(o.new_initializer_))
{
	update_node_list();
}

const type_id_new_expression&
type_id_new_expression::operator=(const type_id_new_expression& o)
{
	leading_double_colon_ = o.leading_double_colon_;
	post_double_colon_space_ = o.post_double_colon_space_;
	post_new_keyword_space_ = o.post_new_keyword_space_;
	new_placement_ = o.new_placement_;
	post_new_placement_space_ = o.post_new_placement_space_;
	post_opening_bracket_space_ = o.post_opening_bracket_space_;
	type_id_ = o.type_id_;
	post_type_id_space_ = o.post_type_id_space_;
	pre_new_initializer_space_ = o.pre_new_initializer_space_;
	new_initializer_ = o.new_initializer_;

	update_node_list();

	return *this;
}

void
type_id_new_expression::update_node_list()
{
	clear();
	if(leading_double_colon_) add(global_nodes::double_colon);
	if(post_double_colon_space_) add(*post_double_colon_space_);
	add(global_nodes::new_keyword);
	if(post_new_keyword_space_) add(*post_new_keyword_space_);
	if(new_placement_) add(*new_placement_);
	if(post_new_placement_space_) add(*post_new_placement_space_);
	add(global_nodes::opening_bracket);
	if(post_opening_bracket_space_) add(*post_opening_bracket_space_);
	add(type_id_);
	if(post_type_id_space_) add(*post_type_id_space_);
	add(global_nodes::closing_bracket);
	if(pre_new_initializer_space_) add(*pre_new_initializer_space_);
	if(new_initializer_) add(*new_initializer_);
}

}}} //namespace socoa::cpp::syntax_nodes

