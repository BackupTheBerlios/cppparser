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

#include "class_elaborated_specifier.hpp"

#include "common_nodes.hpp"

namespace scalpel { namespace cpp { namespace syntax_nodes
{

class_elaborated_specifier::class_elaborated_specifier
(
	class_key&& class_key_node,
	boost::optional<space>&& post_class_key_space_node,
	bool double_colon,
	boost::optional<space>&& post_double_colon_space_node,
	boost::optional<nested_name_specifier>&& nested_name_specifier_node,
	boost::optional<space>&& post_nested_name_specifier_space_node,
	identifier&& identifier_node
):
	class_key_(class_key_node),
	post_class_key_space_(post_class_key_space_node),
	double_colon_(double_colon),
	post_double_colon_space_(post_double_colon_space_node),
	nested_name_specifier_(nested_name_specifier_node),
	post_nested_name_specifier_space_(post_nested_name_specifier_space_node),
	identifier_(identifier_node)
{
	update_node_list();
}

class_elaborated_specifier::class_elaborated_specifier(const class_elaborated_specifier& o):
	composite_node(),
	class_key_(o.class_key_),
	post_class_key_space_(o.post_class_key_space_),
	double_colon_(o.double_colon_),
	post_double_colon_space_(o.post_double_colon_space_),
	nested_name_specifier_(o.nested_name_specifier_),
	post_nested_name_specifier_space_(o.post_nested_name_specifier_space_),
	identifier_(o.identifier_)
{
	update_node_list();
}

class_elaborated_specifier::class_elaborated_specifier(class_elaborated_specifier&& o):
	composite_node(),
	class_key_(std::move(o.class_key_)),
	post_class_key_space_(std::move(o.post_class_key_space_)),
	double_colon_(std::move(o.double_colon_)),
	post_double_colon_space_(std::move(o.post_double_colon_space_)),
	nested_name_specifier_(std::move(o.nested_name_specifier_)),
	post_nested_name_specifier_space_(std::move(o.post_nested_name_specifier_space_)),
	identifier_(std::move(o.identifier_))
{
	update_node_list();
}

const class_elaborated_specifier&
class_elaborated_specifier::operator=(const class_elaborated_specifier& o)
{
	class_key_ = o.class_key_;
	post_class_key_space_ = o.post_class_key_space_;
	double_colon_ = o.double_colon_;
	post_double_colon_space_ = o.post_double_colon_space_;
	nested_name_specifier_ = o.nested_name_specifier_;
	post_nested_name_specifier_space_ = o.post_nested_name_specifier_space_;
	identifier_ = o.identifier_;

	update_node_list();

	return *this;
}

void
class_elaborated_specifier::update_node_list()
{
	clear();
	add(class_key_);
	if(post_class_key_space_) add(*post_class_key_space_);
	if(double_colon_) add(common_nodes::double_colon);
	if(post_double_colon_space_) add(*post_double_colon_space_);
	if(nested_name_specifier_) add(*nested_name_specifier_);
	if(post_nested_name_specifier_space_) add(*post_nested_name_specifier_space_);
	add(identifier_);
}

}}} //namespace scalpel::cpp::syntax_nodes
