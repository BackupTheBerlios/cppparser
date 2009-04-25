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

#include "goto_statement.hpp"

#include "common_nodes.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

goto_statement::goto_statement
(
	boost::optional<space>&& post_return_space_node,
	identifier&& identifier_node,
	boost::optional<space>&& post_identifier_space_node
):
	post_return_space_(post_return_space_node),
	identifier_(identifier_node),
	post_identifier_space_(post_identifier_space_node)
{
	update_node_list();
}

goto_statement::goto_statement(const goto_statement& o):
	composite_node(),
	post_return_space_(o.post_return_space_),
	identifier_(o.identifier_),
	post_identifier_space_(o.post_identifier_space_)
{
	update_node_list();
}

goto_statement::goto_statement(goto_statement&& o):
	composite_node(),
	post_return_space_(std::move(o.post_return_space_)),
	identifier_(std::move(o.identifier_)),
	post_identifier_space_(std::move(o.post_identifier_space_))
{
	update_node_list();
}

const goto_statement&
goto_statement::operator=(const goto_statement& o)
{
	post_return_space_ = o.post_return_space_;
	identifier_ = o.identifier_;
	post_identifier_space_ = o.post_identifier_space_;

	update_node_list();

	return *this;
}

void
goto_statement::update_node_list()
{
	clear();
	if(post_return_space_) add(*post_return_space_);
	add(identifier_);
	if(post_identifier_space_) add(*post_identifier_space_);
}

}}} //namespace socoa::cpp::syntax_nodes
