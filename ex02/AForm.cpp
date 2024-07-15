/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:17:04 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/15 17:09:11 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
AForm::AForm() : _is_signed(AFORM_DFT_IS_SIGNED), _target(AFORM_DFT_TARGET)
{
}

AForm::AForm(const std::string& target) : _is_signed(AFORM_DFT_IS_SIGNED), _target(target)
{
}

AForm::AForm(const AForm &src) : _is_signed(src.getIsSigned()), _target(src.getTarget())
{
}

// Destructors
AForm::~AForm()
{
}

// Operators
/* CAUTION: Assigns only "is_signed" status */
AForm&	AForm::operator=(const AForm &assign)
{
	_is_signed = assign.getIsSigned();
	return *this;
}

// Exception classes
const char*	AForm::GradeTooHighException::what( void ) const throw()
{
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low";
}

const char*	AForm::FormAlreadySigned::what( void ) const throw()
{
	return "Form is already signed";
}

const char*	AForm::FormIsNotSigned::what( void ) const throw()
{
	return "Form is not signed";
}

// Getters / Setters
void	AForm::setIsSigned(bool is_signed)
{
	_is_signed = is_signed;
}

bool				AForm::getIsSigned( void ) const
{
	return _is_signed;
}

const std::string &	AForm::getTarget( void ) const
{
	return _target;
}

// Actions
void	AForm::beSigned(const Bureaucrat& signer) throw (GradeTooLowException, GradeTooHighException, FormAlreadySigned)
{
	int	grade;

	grade = signer.getGrade();
	if (grade < AFORM_MIN_GRADE)
		throw GradeTooHighException();
	if (grade > AFORM_MAX_GRADE || grade > getSignGrade())
		throw GradeTooLowException();
	if (_is_signed)
		throw FormAlreadySigned();
	_is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const throw (GradeTooHighException, GradeTooLowException, FormIsNotSigned)
{
	int	grade;

	if (!_is_signed)
		throw FormIsNotSigned();
	grade = executor.getGrade();
	if (grade < AFORM_MIN_GRADE)
		throw GradeTooHighException();
	if (grade > AFORM_MAX_GRADE || grade > getExecGrade())
		throw GradeTooLowException();
	performExecution();
}

// Stream operators
std::ostream&	operator<<(std::ostream& out, const AForm& rhs)
{
	out << "Form \"" << rhs.getName() << "\" : status(";
	if (!rhs.getIsSigned())
		out << "un";
	out << "signed), grade to sign(" << rhs.getSignGrade() << "), grade to execute("<< rhs.getExecGrade() << ")" << ", target(" << rhs.getTarget() << ')' << std::endl;
	return out;
}
