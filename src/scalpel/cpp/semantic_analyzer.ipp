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

#ifndef SCALPEL_CPP_SEMANTIC_ANALYZER_IPP
#define SCALPEL_CPP_SEMANTIC_ANALYZER_IPP

#include "detail/semantic_analysis/basic_functions.hpp"
#include "detail/semantic_analysis/name_lookup.hpp"

namespace scalpel { namespace cpp
{

template<class ParentEntityT>
semantic_analyzer::alternative_visitor<ParentEntityT>::alternative_visitor(semantic_analyzer& analyzer, std::shared_ptr<ParentEntityT> parent_entity):
	analyzer_(analyzer),
	parent_entity_(parent_entity)
{
}

template<class ParentEntityT>
template<class T>
inline
void
semantic_analyzer::alternative_visitor<ParentEntityT>::operator()(const T& syntax_node) const
{
	analyzer_.analyze(syntax_node, parent_entity_);
}



template<class SyntaxNodeT, class EntityT>
void
semantic_analyzer::analyze
(
	const SyntaxNodeT& syntax_node,
	std::shared_ptr<EntityT> parent_entity,
	typename boost::enable_if<syntax_nodes::utility::is_alternative_node<SyntaxNodeT>>::type*
)
{
	alternative_visitor<EntityT> visitor(*this, parent_entity);
	syntax_nodes::apply_visitor(visitor, syntax_node);
}

template<class SyntaxNodeT, class EntityT>
void
semantic_analyzer::analyze
(
	const SyntaxNodeT& syntax_node,
	std::shared_ptr<EntityT> parent_entity,
	typename boost::enable_if<syntax_nodes::utility::is_list_node<SyntaxNodeT>>::type*
)
{
	for(auto i = syntax_node.begin(); i != syntax_node.end(); ++i)
	{
		analyze(i->main_node(), parent_entity);
	}
}



template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::asm_definition&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::break_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::case_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::class_head&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::class_specifier& class_specifier_node, std::shared_ptr<EntityT> parent_entity)
{
	using namespace syntax_nodes;
	using namespace semantic_entities;

	std::shared_ptr<class_> new_class = create_class(class_specifier_node);
	parent_entity->add(new_class);
	scope_cursor_.enter_scope(new_class);
	fill_class(new_class, class_specifier_node);
	scope_cursor_.leave_scope();
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::classic_labeled_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::compound_statement& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	/*
	if(create_statement_block)
	{
		std::shared_ptr<statement_block> s = std::make_shared<statement_block>();
		scope_cursor_.add_to_current_scope(s);
		scope_cursor_.enter_last_added_scope();
	}

	auto opt_statement_seq_node = get_statement_seq(syntax_node);
	if(opt_statement_seq_node)
	{
		analyze(*opt_statement_seq_node);
	}

	if(create_statement_block)
	{
		scope_cursor_.leave_scope();
	}
	*/
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::continue_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::conversion_function_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::ctor_initializer&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::cv_qualifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::declarator&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::default_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::destructor_name&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::direct_declarator&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::direct_declarator_array_part&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::direct_declarator_function_part&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::do_while_statement& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	//analyze(get_statement(syntax_node));
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::elaborated_type_specifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::explicit_instantiation&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::explicit_specialization&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::expression_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::for_statement& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	//analyze(get_statement(syntax_node));
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::function_definition& function_definition_node, std::shared_ptr<EntityT> parent_entity)
{
	using namespace syntax_nodes;
	using namespace semantic_entities;
	using namespace detail::semantic_analysis;

	auto direct_declarator_node = get_direct_declarator(get_declarator(function_definition_node));

	//
	//get the enclosing scope of the function
	//
	std::shared_ptr<scope> enclosing_scope;

	const direct_declarator_first_part& first_part_node = get_first_part(direct_declarator_node);
	boost::optional<const declarator_id&> direct_node_id = get<declarator_id>(&first_part_node);
	if(direct_node_id)
	{
		boost::optional<const id_expression&> id_expression_node = get<id_expression>(direct_node_id);
		if(id_expression_node)
		{
			boost::optional<const unqualified_id&> unqualified_id_node = get<unqualified_id>(id_expression_node);
			boost::optional<const qualified_id&> a_qualified_id = get<qualified_id>(id_expression_node);

			if(unqualified_id_node)
			{
				enclosing_scope = scope_cursor_.current_scope();
			}
			else if(a_qualified_id)
			{
			//	const qualified_identifier* const a_qualified_identifier =
			//		boost::get<qualified_identifier>(a_qualified_id)
			//	;
				boost::optional<const qualified_nested_id&> a_qualified_nested_id = get<qualified_nested_id>(a_qualified_id);
			//	const qualified_operator_function_id* const a_qualified_operator_function_id =
			//	   	boost::get<qualified_operator_function_id>(a_qualified_id)
			//	;
			//	const qualified_template_id* const a_qualified_template_id =
			//	   	boost::get<qualified_template_id>(a_qualified_id)
			//	;

				if(a_qualified_nested_id)
				{
					bool leading_double_colon = has_double_colon(*a_qualified_nested_id);
					const nested_name_specifier& a_nested_name_specifier = get_nested_name_specifier(*a_qualified_nested_id);

					if(leading_double_colon)
					{
						enclosing_scope = name_lookup::find_scope(scope_cursor_.global_scope_stack(), a_nested_name_specifier);
					}
					else
					{
						enclosing_scope = name_lookup::find_scope(scope_cursor_.scope_stack(), a_nested_name_specifier);
					}
				}
			}
			else
			{
				assert(false);
			}
		}
	}

	if(auto opt_decl_specifier_seq_node = get_decl_specifier_seq(function_definition_node))
	{
		//create a function object
		auto decl_specifier_seq_node = *opt_decl_specifier_seq_node;
		auto declarator_node = get_declarator(function_definition_node);
		std::shared_ptr<function> new_function = create_function(decl_specifier_seq_node, declarator_node);

		//find the corresponding function semantic node (must exist if the function has already been declared)
		std::shared_ptr<scope> function_scope;
		if(enclosing_scope)
		{
			auto scopes = enclosing_scope->scopes();
			for(auto i = scopes.begin(); i != scopes.end(); ++i)
			{
				std::shared_ptr<scope> scope = *i;

				///\todo check the function's signature
				if(scope->name() == new_function->name())
				{
					function_scope = scope;
					break;
				}
			}
		}

		//if the function hasn't been declared, this definition serves as a declaration
		if(!function_scope)
		{
			parent_entity->add(new_function);
			function_scope = scope_cursor_.current_scope()->scopes().back();
		}

		//enter and leave the function body
		if(function_scope)
		{
			/*
			scope_cursor_.enter_scope(*function_scope);

			if(auto opt_simple_function_definition = get<simple_function_definition>(&function_definition_node))
			{
				auto compound_statement_node = get_compound_statement(*opt_simple_function_definition);
				analyze(compound_statement_node, false);
			}

			scope_cursor_.leave_scope();
			*/
		}
	}
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::goto_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::handler& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	//analyze(get_compound_statement(syntax_node));
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::identifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::if_statement& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	/*
	analyze(get_statement(syntax_node));

	auto opt_else_statement_node = get_else_statement(syntax_node);
	if(opt_else_statement_node)
		analyze(*opt_else_statement_node);
		*/
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::init_declarator&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::linkage_specification&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::mem_initializer&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_declaration_function_definition&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_declaration_member_declarator_list&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_declaration_unqualified_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_declarator_bit_field_member&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_declarator_declarator&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_specification&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::member_specification_access_specifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::namespace_alias_definition&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::namespace_definition& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	using namespace syntax_nodes;
	using namespace semantic_entities;

	//get the namespace name
	std::string namespace_name;
	const optional_node<identifier>& identifier_node = get_identifier(syntax_node);
	if(identifier_node)
	{
		namespace_name = identifier_node->value();
	}

	//create the namespace entity
	std::shared_ptr<namespace_> new_namespace = std::make_shared<namespace_>(namespace_name);

	//add the namespace to the current scope
	parent_entity->add(new_namespace);

	//add the declarations of the namespace definition in the namespace semantic node
	scope_cursor_.enter_scope(new_namespace);
	const optional_node<declaration_seq>& a_declaration_seq = get_declaration_seq(syntax_node);
	if(a_declaration_seq)
	{
		analyze(*a_declaration_seq, new_namespace);
	}
	scope_cursor_.leave_scope();
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::nested_identifier_or_template_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::nested_name_specifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::nested_name_specifier_last_part&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::operator_function_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::parameter_declaration&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::parameter_declaration_clause&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::ptr_operator&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::qualified_identifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::qualified_nested_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::qualified_operator_function_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::qualified_template_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::return_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::simple_declaration& simple_declaration_node, std::shared_ptr<EntityT> parent_entity)
{
	using namespace syntax_nodes;
	using namespace semantic_entities;
	using namespace detail::semantic_analysis;

	std::vector<std::string> names;
	std::string class_name;
	bool is_a_class_declaration = false;
	bool is_a_class_forward_declaration = false;
	bool is_a_function_declaration = false;
	bool is_an_operator_function_declaration = false;

	const optional_node<decl_specifier_seq>& opt_decl_specifier_seq_node = get_decl_specifier_seq(simple_declaration_node);
	const optional_node<init_declarator_list>& opt_init_declarator_list_node = get_init_declarator_list(simple_declaration_node);

	if(opt_decl_specifier_seq_node)
	{
		const decl_specifier_seq& decl_specifier_seq_node = *opt_decl_specifier_seq_node;
		for(auto i = decl_specifier_seq_node.begin(); i != decl_specifier_seq_node.end(); ++i)
		{
			const decl_specifier& a_decl_specifier = i->main_node();

			if(auto a_type_specifier_ptr = get<type_specifier>(&a_decl_specifier))
			{
				if(auto opt_class_specifier_node = get<class_specifier>(a_type_specifier_ptr))
				{
					is_a_class_declaration = true;
					analyze(*opt_class_specifier_node, parent_entity);
				}
				else if(auto an_elaborated_type_specifier_ptr = get<elaborated_type_specifier>(a_type_specifier_ptr))
				{
					//const class_template_elaborated_specifier* = get<>;
					//const enum_elaborated_specifier* ;
					//const typename_template_elaborated_specifier* ;
					//const typename_elaborated_specifier* ;

					if
					(
						auto opt_class_elaborated_specifier_node = get<class_elaborated_specifier>
						(
							an_elaborated_type_specifier_ptr
						)
					)
					{
						is_a_class_forward_declaration = true;
						const identifier_or_template_id& identifier_or_template_id_node = get_identifier_or_template_id(*opt_class_elaborated_specifier_node);
						if(auto identifier_node = get<identifier>(&identifier_or_template_id_node))
						{
							class_name = identifier_node->value();
						}
					}
				}
			}
		}
	}

	if(opt_init_declarator_list_node)
	{
		const init_declarator_list& an_init_declarator_list = *opt_init_declarator_list_node;
		for(auto i = an_init_declarator_list.begin(); i != an_init_declarator_list.end(); ++i)
		{
			const declarator& declarator_node = get_declarator(i->main_node());
			const direct_declarator& direct_declarator_node = get_direct_declarator(declarator_node);

			//get the simple_declaration_node name
			const direct_declarator_first_part& first_part_node = get_first_part(direct_declarator_node);
			const boost::optional<const declarator_id&> opt_declarator_id_node = get<declarator_id>(&first_part_node);
			if(opt_declarator_id_node)
			{
				const declarator_id& declarator_id_node = *opt_declarator_id_node;
				if(boost::optional<const id_expression&> id_expression_node = get<id_expression>(&declarator_id_node))
				{
					if(boost::optional<const unqualified_id&> unqualified_id_node = get<unqualified_id>(id_expression_node))
					{
						if(boost::optional<const identifier&> identifier_node = get<identifier>(unqualified_id_node))
						{
							names.push_back(identifier_node->value());
						}
					}
				}
			}

			if(!is_a_function_declaration)
			{
				is_a_function_declaration = is_function_declaration(declarator_node);
				if(is_a_function_declaration)
				{
					is_an_operator_function_declaration = is_operator_function_declaration(declarator_node);
				}
			}
		}
	}

	if(is_a_class_declaration)
	{
		//analysis is already done
	}
	else if(is_a_class_forward_declaration)
	{
		if(!class_name.empty())
			parent_entity->add(std::make_shared<class_>(class_name));
	}
	else if(is_an_operator_function_declaration)
	{
		assert(opt_decl_specifier_seq_node);
		assert(opt_init_declarator_list_node);
		auto init_declarator_list_node = *opt_init_declarator_list_node;
		assert(init_declarator_list_node.size() == 1);

		auto decl_specifier_seq_node = *opt_decl_specifier_seq_node;
		auto declarator_node = get_declarator(init_declarator_list_node.front().main_node());
		parent_entity->add(create_operator_function(decl_specifier_seq_node, declarator_node));
	}
	else if(is_a_function_declaration)
	{
		assert(opt_decl_specifier_seq_node);
		assert(opt_init_declarator_list_node);
		auto init_declarator_list_node = *opt_init_declarator_list_node;
		assert(init_declarator_list_node.size() == 1);

		auto decl_specifier_seq_node = *opt_decl_specifier_seq_node;
		auto declarator_node = get_declarator(init_declarator_list_node.front().main_node());
		parent_entity->add(create_function(decl_specifier_seq_node, declarator_node));
	}
	else //variable declaration
	{
		assert(opt_decl_specifier_seq_node);
		const decl_specifier_seq& decl_specifier_seq_node = *opt_decl_specifier_seq_node;

		auto opt_init_declarator_list_node = get_init_declarator_list(simple_declaration_node);
		assert(opt_init_declarator_list_node);
		auto init_declarator_list_node = *opt_init_declarator_list_node;

		std::vector<std::shared_ptr<variable>> variables = create_variables(decl_specifier_seq_node, init_declarator_list_node);
		//for each variable
		for
		(
			auto i = variables.begin();
			i != variables.end();
			++i
		)
		{
			parent_entity->add(*i);
		}
	}
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::simple_template_type_specifier&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::switch_statement&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::template_declaration&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::template_id&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::try_block& syntax_node, std::shared_ptr<EntityT> parent_entity)
{
	/*
	analyze(get_compound_statement(syntax_node));
	analyze(get_handler_seq(syntax_node));
	*/
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::type_id_sizeof_expression&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::unary_sizeof_expression&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::using_declaration&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::using_directive&, std::shared_ptr<EntityT>)
{
}

template<class EntityT>
void
semantic_analyzer::analyze(const syntax_nodes::while_statement&, std::shared_ptr<EntityT>)
{
}

}} //namespace scalpel::cpp

#endif

