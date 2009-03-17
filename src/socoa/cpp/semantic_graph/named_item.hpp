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

#ifndef SOCOA_CPP_SEMANTIC_GRAPH_NAMED_ITEM_HPP
#define SOCOA_CPP_SEMANTIC_GRAPH_NAMED_ITEM_HPP

#include <string>

namespace socoa { namespace cpp { namespace semantic_graph
{

struct named_item
{
	virtual
	~named_item(){}

	/**
	@return the name of the item
	*/
	virtual
	const std::string&
	get_name() const = 0;

	/**
	@return true if the item has the given name
	*/
	virtual
	bool
	has_that_name(const std::string& name) const = 0;

	virtual
	bool
	is_a_type() const = 0;
};

}}} //namespace socoa::cpp::semantic_graph

#endif
