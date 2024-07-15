/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:47:40 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/15 15:36:39 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException)\
try : AForm(SHRUBBERYCREATIONFORM_DFT_NAME, SHRUBBERYCREATIONFORM_DFT_SIGN_GRADE, SHRUBBERYCREATIONFORM_DFT_EXEC_GRADE, SHRUBBERYCREATIONFORM_DFT_TARGET)
{
	if (getSignGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE || getExecGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE || getExecGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}
catch (std::exception& e)
{
	std::cerr << "Failed to construct Base class AForm: " << e.what() << std::endl;
	throw;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, int sign_grade, int exec_grade, const std::string& target) \
throw (AForm::GradeTooHighException, AForm::GradeTooLowException) \
try : AForm(name, sign_grade, exec_grade, target)
{
	if (getSignGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE || getExecGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE || getExecGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}
catch (std::exception& e)
{
	std::cerr << "Failed to construct Base class AForm: " << e.what() << std::endl;
	throw;
}
