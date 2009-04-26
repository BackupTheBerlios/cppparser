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
const boost::optional<const declarator_id&>
direct_declarator::get_declarator_id() const
{
	return boost::optional<const declarator_id&>(declarator_id_);
}

inline
const boost::optional<const declarator&>
direct_declarator::get_declarator() const
{
	return boost::optional<const declarator&>(declarator_);
}

inline
const boost::optional<const direct_declarator::next_part_seq&>
direct_declarator::get_next_part_seq() const
{
	return boost::optional<const direct_declarator::next_part_seq&>(next_part_seq_);
}


inline
const boost::optional<const parameter_declaration_clause&>
direct_declarator::function_part::get_parameter_declaration_clause() const
{
    return boost::optional<const parameter_declaration_clause&>(parameter_declaration_clause_);
}

inline
const boost::optional<const cv_qualifier_seq&>
direct_declarator::function_part::get_cv_qualifier_seq() const
{
	return boost::optional<const cv_qualifier_seq&>(*cv_qualifier_seq_);
}

}}} //namespace socoa::cpp::syntax_nodes

#endif

