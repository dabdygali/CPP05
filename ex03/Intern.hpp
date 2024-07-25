/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:04:21 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:16:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	_INTERN_HPP_
	#define	_INTERN_HPP_

	#include <string>
	#include "AForm.hpp"

	#define INTERN_FORMS_VARIETY_QTY	3

	typedef struct s_FormCreatorPair
	{
		public:
			const std::string	formName;
			AForm*				(*const formCreator)(const std::string&);

			s_FormCreatorPair(const std::string& name, AForm* (*const creator)(const std::string&));			
	}	t_FormCreatorPair;
	
	class Intern
	{
		private:
			static t_FormCreatorPair	_map[INTERN_FORMS_VARIETY_QTY];
			
		public:			
			Intern();
			Intern(const Intern& src);
			Intern&	operator=(const Intern& assign);
			virtual ~Intern();
			
			AForm	*makeForm(const std::string& name, const std::string& target);
	};
#endif
