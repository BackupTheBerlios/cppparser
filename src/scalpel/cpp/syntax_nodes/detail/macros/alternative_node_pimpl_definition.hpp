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

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/seq.hpp>

#define SCALPEL_ALTERNATIVE_NODE_PIMPL_DEFINITION_CONSTRUCTOR(r, alternative_node_type, node_type) \
alternative_node_type::alternative_node_type(node_type&& o): \
	impl_(new type(o)) \
{ \
}

#define SCALPEL_ALTERNATIVE_NODE_PIMPL_DEFINITION_GET_FUNCTION(r, alternative_node_type, node_type) \
void \
alternative_node_type::get(boost::optional<const node_type&>& node) const \
{ \
	impl_->get(node); \
}

#define SCALPEL_ALTERNATIVE_NODE_PIMPL_DEFINITION(alternative_node_type, type_seq)  \
BOOST_PP_SEQ_FOR_EACH                                                               \
(                                                                                   \
	SCALPEL_ALTERNATIVE_NODE_PIMPL_DEFINITION_CONSTRUCTOR,                          \
	alternative_node_type,                                                          \
	type_seq                                                                        \
)                                                                                   \
                                                                                    \
alternative_node_type::alternative_node_type(const alternative_node_type& o):       \
	impl_(new type(*o.impl_))                                                       \
{                                                                                   \
}                                                                                   \
                                                                                    \
alternative_node_type::alternative_node_type(alternative_node_type&& o):            \
	impl_(std::move(o.impl_))                                                       \
{                                                                                   \
}                                                                                   \
                                                                                    \
alternative_node_type::~alternative_node_type()                                     \
{                                                                                   \
}                                                                                   \
                                                                                    \
const alternative_node_type&                                                        \
alternative_node_type::operator=(const alternative_node_type& o)                    \
{                                                                                   \
	*impl_ = *o.impl_;                                                              \
	return *this;                                                                   \
}                                                                                   \
                                                                                    \
const std::string                                                                   \
alternative_node_type::value() const                                                \
{                                                                                   \
	return impl_->value();                                                          \
}                                                                                   \
                                                                                    \
node::child_const_iterator_range                                                    \
alternative_node_type::children() const                                             \
{                                                                                   \
	return impl_->children();                                                       \
}                                                                                   \
                                                                                    \
BOOST_PP_SEQ_FOR_EACH                                                               \
(                                                                                   \
	SCALPEL_ALTERNATIVE_NODE_PIMPL_DEFINITION_GET_FUNCTION,                         \
	alternative_node_type,                                                          \
	type_seq                                                                        \
)
