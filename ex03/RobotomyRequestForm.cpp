/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:47:40 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:12:36 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <new>
#include "RobotomyRequestForm.hpp"

// Static Attributes
const std::string	RobotomyRequestForm::_sName = ROBOTOMYREQUESTFORM_DFT_NAME;
const int			RobotomyRequestForm::_sGradeToSign = ROBOTOMYREQUESTFORM_DFT_SIGN_GRADE;
const int			RobotomyRequestForm::_sGradeToExecute = ROBOTOMYREQUESTFORM_DFT_EXEC_GRADE;

// Constructors
RobotomyRequestForm::RobotomyRequestForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(ROBOTOMYREQUESTFORM_DFT_TARGET)
{
	if (getSignGrade() < ROBOTOMYREQUESTFORM_MIN_GRADE || getExecGrade() < ROBOTOMYREQUESTFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > ROBOTOMYREQUESTFORM_MAX_GRADE || getExecGrade() > ROBOTOMYREQUESTFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(target)
{
	if (getSignGrade() < ROBOTOMYREQUESTFORM_MIN_GRADE || getExecGrade() < ROBOTOMYREQUESTFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > ROBOTOMYREQUESTFORM_MAX_GRADE || getExecGrade() > ROBOTOMYREQUESTFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(src)
{
	if (getSignGrade() < ROBOTOMYREQUESTFORM_MIN_GRADE || getExecGrade() < ROBOTOMYREQUESTFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > ROBOTOMYREQUESTFORM_MAX_GRADE || getExecGrade() > ROBOTOMYREQUESTFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

// Destructors
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Operators
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& assign)
{
	AForm::operator=(assign);
	return *this;
}

// Getters / Setters
const std::string&	RobotomyRequestForm::getName( void ) const
{
	return _sName;
}

int					RobotomyRequestForm::getSignGrade( void ) const
{
	return _sGradeToSign;
}

int					RobotomyRequestForm::getExecGrade( void ) const
{
	return _sGradeToExecute;
}

// Factory
AForm*	RobotomyRequestForm::newRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

// Actions
void	RobotomyRequestForm::performExecution( void ) const
{
	std::cout << "*Some Drilling noises*" << std::endl;
	srand((unsigned int) time(NULL));
	if (rand() % 2)
		std::cout << getTarget() << " has been successfully robotomized" << std::endl;
	else
		std::cout << getTarget() << " robotomy failed" << std::endl;
}
