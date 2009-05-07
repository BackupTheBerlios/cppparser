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

#ifndef SOCOA_CPP_SYNTAX_NODES_DIRECT_DECLARATOR_IPP
#define SOCOA_CPP_SYNTAX_NODES_DIRECT_DECLARATOR_IPP

namespace socoa { namespace cpp { namespace syntax_nodes
{

inline
const direct_declarator::first_part&
direct_declarator::first_part_node() const
{
	return first_part_;
}

inline
const boost::optional<const direct_declarator::last_part_seq&>
direct_declarator::last_part_seq_node() const
{
	return boost::optional<const direct_declarator::last_part_seq&>(last_part_seq_);
}


inline
const boost::optional<const parameter_declaration_clause&>
direct_declarator::function_part::parameter_declaration_clause_node() const
{
    return boost::optional<const parameter_declaration_clause&>(parameter_declaration_clause_);
}

inline
const boost::optional<const cv_qualifier_seq&>
direct_declarator::function_part::cv_qualifier_seq_node() const
{
	return boost::optional<const cv_qualifier_seq&>(*cv_qualifier_seq_);
}

}}} //namespace socoa::cpp::syntax_nodes

#endif

