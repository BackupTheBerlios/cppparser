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

#ifndef SOCOA_CPP_SYNTAX_NODES_THROW_EXPRESSION_HPP
#define SOCOA_CPP_SYNTAX_NODES_THROW_EXPRESSION_HPP

#include <memory>
#include <boost/optional.hpp>
#include "composite_node.hpp"
#include "space.hpp"

namespace socoa { namespace cpp { namespace syntax_nodes
{

class assignment_expression;

/**
throw_expression
	= "throw", [assignment_expression]
;
*/
class throw_expression: public composite_node
{
	public:
		throw_expression
		(
			boost::optional<space>&& pre_assignment_expression_space_node,
			boost::optional<assignment_expression>&& assignment_expression_node
		);

		throw_expression(const throw_expression& o);

		throw_expression(throw_expression&& o);

		const throw_expression&
		operator=(const throw_expression& o);

	private:
		void
		update_node_list();

		boost::optional<space> pre_assignment_expression_space_;
		std::unique_ptr<assignment_expression> assignment_expression_;
};

}}} //namespace socoa::cpp::syntax_nodes

#endif
