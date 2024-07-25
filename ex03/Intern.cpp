/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:16:21 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:40:31 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

s_FormCreatorPair::s_FormCreatorPair(const std::string& name, AForm* (*const creator)(const std::string&)) : formName(name), formCreator(creator)
{
}

t_FormCreatorPair	Intern::_map[INTERN_FORMS_VARIETY_QTY] = {
	s_FormCreatorPair(SHRUBBERYCREATIONFORM_DFT_NAME, ShrubberyCreationForm::newShrubberyCreationForm),
	s_FormCreatorPair(ROBOTOMYREQUESTFORM_DFT_NAME, RobotomyRequestForm::newRobotomyRequestForm),
	s_FormCreatorPair(PRESIDENTIALPARDONFORM_DFT_NAME, PresidentialPardonForm::newPresidentialPardonForm)
};

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	Intern const * ptr;

	ptr = &src;
	ptr++;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& assign)
{
	Intern const * ptr;

	ptr = &assign;
	ptr++;
	return *this;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	int	i;
	AForm*	ptr;

	ptr = NULL;
	i = 0;
	while (i < INTERN_FORMS_VARIETY_QTY)
	{
		if (!_map[i].formName.compare(name))
		{
			try
			{
				ptr = _map[i].formCreator(target);
			}
			catch(std::exception& e)
			{
				std::cout << "Intern failed to create a " << name << " form: " << e.what() << std::endl;
				return NULL;
			}
			std::cout << "Intern creates " << name << " form" << std::endl;
			return ptr;
		}
		i++;
	}
	std::cout << "Intern couldn't find the " << name << " form" << std::endl;
	return NULL;
}
