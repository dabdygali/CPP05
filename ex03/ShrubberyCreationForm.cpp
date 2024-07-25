/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:47:40 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:12:16 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sys/stat.h>
#include <stdexcept>
#include <new>
#include "ShrubberyCreationForm.hpp"

// Static Attributes
const std::string	ShrubberyCreationForm::_sName = SHRUBBERYCREATIONFORM_DFT_NAME;
const int			ShrubberyCreationForm::_sGradeToSign = SHRUBBERYCREATIONFORM_DFT_SIGN_GRADE;
const int			ShrubberyCreationForm::_sGradeToExecute = SHRUBBERYCREATIONFORM_DFT_EXEC_GRADE;

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(SHRUBBERYCREATIONFORM_DFT_TARGET)
{
	if (getSignGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE || getExecGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE || getExecGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(target)
{
	if (getSignGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE || getExecGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE || getExecGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) throw (AForm::GradeTooHighException, AForm::GradeTooLowException) : AForm(src)
{
	if (getSignGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE || getExecGrade() < SHRUBBERYCREATIONFORM_MIN_GRADE)
		throw AForm::GradeTooHighException();
	if (getSignGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE || getExecGrade() > SHRUBBERYCREATIONFORM_MAX_GRADE)
		throw AForm::GradeTooLowException();
}

// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Operators
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign)
{
	AForm::operator=(assign);
	return *this;
}

// Getters / Setters
const std::string&	ShrubberyCreationForm::getName( void ) const
{
	return _sName;
}

int					ShrubberyCreationForm::getSignGrade( void ) const
{
	return _sGradeToSign;
}

int					ShrubberyCreationForm::getExecGrade( void ) const
{
	return _sGradeToExecute;
}

// Factory
AForm*	ShrubberyCreationForm::newShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

// Actions
void	ShrubberyCreationForm::performExecution( void ) const
{
	std::string		fileName(getTarget() + "_shrubbery");
	std::ofstream	ofs;
	struct stat		fileInfo;

	if (stat(fileName.c_str(), &fileInfo) == 0)
		throw std::runtime_error("File \"" + fileName + "\" already exists");
	ofs.open(fileName.c_str());
	if (!ofs.good())
		throw std::runtime_error("Error opening file \"" + fileName + '\"');
	ofs << SHRUBBERYCREATIONFORM_DFT_ASCII_TREE << std::endl;
	ofs << SHRUBBERYCREATIONFORM_DFT_ASCII_TREE << std::endl;
}
