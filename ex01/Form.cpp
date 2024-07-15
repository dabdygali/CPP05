/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:17:04 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/12 17:55:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form() throw (GradeTooHighException, GradeTooLowException) \
: _name(FORM_DFT_NAME), _is_signed(FORM_DFT_IS_SIGNED), \
_sign_grade(FORM_DFT_SIGN_GRADE), _exec_grade(FORM_DFT_EXEC_GRADE)
{
	if (_sign_grade < FORM_MIN_GRADE || _exec_grade < FORM_MIN_GRADE)
		throw GradeTooHighException();
	if (_sign_grade > FORM_MAX_GRADE || _exec_grade > FORM_MAX_GRADE)
		throw GradeTooLowException();
}

Form::Form(const std::string &name, int sign_grade, int exec_grade) \
throw (GradeTooHighException, GradeTooLowException) : _name(name), \
_is_signed(FORM_DFT_IS_SIGNED), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < FORM_MIN_GRADE || _exec_grade < FORM_MIN_GRADE)
		throw GradeTooHighException();
	if (_sign_grade > FORM_MAX_GRADE || _exec_grade > FORM_MAX_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &src) throw (GradeTooHighException, GradeTooLowException) \
: _name(src.getName()), _is_signed(src.getIsSigned()), \
_sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	if (_sign_grade < FORM_MIN_GRADE || _exec_grade < FORM_MIN_GRADE)
		throw GradeTooHighException();
	if (_sign_grade > FORM_MAX_GRADE || _exec_grade > FORM_MAX_GRADE)
		throw GradeTooLowException();
}

// Destructors
Form::~Form()
{
}

// Operators
/* CAUTION: Assigns only "is_signed" status */
Form&	Form::operator=(const Form &assign)
{
	_is_signed = assign.getIsSigned();
	return *this;
}

// Exception classes
const char*	Form::GradeTooHighException::what( void ) const throw()
{
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low";
}

const char*	Form::FormAlreadySigned::what( void ) const throw()
{
	return "Form is already signed";
}

// Getters / Setters
void	Form::setIsSigned(bool is_signed)
{
	_is_signed = is_signed;
}

const std::string&	Form::getName( void ) const
{
	return _name;
}

bool				Form::getIsSigned( void ) const
{
	return _is_signed;
}

int					Form::getSignGrade( void ) const
{
	return _sign_grade;
}

int					Form::getExecGrade( void ) const
{
	return _exec_grade;
}

// Actions
void	Form::beSigned(const Bureaucrat& by_who) throw (GradeTooLowException, GradeTooHighException, FormAlreadySigned)
{
	int	grade;

	grade = by_who.getGrade();
	if (grade < FORM_MIN_GRADE)
		throw GradeTooHighException();
	if (grade > FORM_MAX_GRADE || grade > _sign_grade)
		throw GradeTooLowException();
	if (_is_signed)
		throw FormAlreadySigned();
	_is_signed = true;
}

// Stream operators
std::ostream&	operator<<(std::ostream& out, const Form& rhs)
{
	out << "Form \"" << rhs.getName() << "\" : status(";
	if (!rhs.getIsSigned())
		out << "un";
	out << "signed), grade to sign(" << rhs.getSignGrade() << "), grade to execute(" << rhs.getExecGrade() << ")" << std::endl;
	return out;
}
