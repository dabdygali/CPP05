/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:47:40 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:15:45 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new>
#include "PresidentialPardonForm.hpp"

// Static Attributes
const std::string	PresidentialPardonForm::_sName = PRESIDENTIALPARDONFORM_DFT_NAME;
const int			PresidentialPardonForm::_sGradeToSign = PRESIDENTIALPARDONFORM_DFT_SIGN_GRADE;
const int			PresidentialPardonForm::_sGradeToExecute = PRESIDENTIALPARDONFORM_DFT_EXEC_GRADE;

// Constructors
PresidentialPardonForm::PresidentialPardonForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(PRESIDENTIALPARDONFORM_DFT_TARGET)
{
	if (getSignGrade() < PRESIDENTIALPARDONFORM_MIN_GRADE || getExecGrade() < PRESIDENTIALPARDONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > PRESIDENTIALPARDONFORM_MAX_GRADE || getExecGrade() > PRESIDENTIALPARDONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(target)
{
	if (getSignGrade() < PRESIDENTIALPARDONFORM_MIN_GRADE || getExecGrade() < PRESIDENTIALPARDONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > PRESIDENTIALPARDONFORM_MAX_GRADE || getExecGrade() > PRESIDENTIALPARDONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(src)
{
	if (getSignGrade() < PRESIDENTIALPARDONFORM_MIN_GRADE || getExecGrade() < PRESIDENTIALPARDONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > PRESIDENTIALPARDONFORM_MAX_GRADE || getExecGrade() > PRESIDENTIALPARDONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

// Destructors
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Operators
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& assign)
{
	AForm::operator=(assign);
	return *this;
}

// Factory
AForm*	PresidentialPardonForm::newPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

// Getters / Setters
const std::string&	PresidentialPardonForm::getName( void ) const
{
	return _sName;
}

int					PresidentialPardonForm::getSignGrade( void ) const
{
	return _sGradeToSign;
}

int					PresidentialPardonForm::getExecGrade( void ) const
{
	return _sGradeToExecute;
}

// Actions
void	PresidentialPardonForm::performExecution( void ) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
