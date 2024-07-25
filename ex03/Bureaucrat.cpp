/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:16:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/17 16:14:06 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() throw (GradeTooHighException, GradeTooLowException) : _name(BUREAUCRAT_DFT_NAME), _grade(BUREAUCRAT_MAX_GRADE)
{
	if (BUREAUCRAT_DFT_GRADE > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (BUREAUCRAT_DFT_GRADE < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade = BUREAUCRAT_DFT_GRADE;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) throw (GradeTooHighException, GradeTooLowException) : _name(name)
{
	if (grade > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (grade < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) throw (GradeTooHighException, GradeTooLowException) : _name(src.getName())
{
	int	grade;

	grade = src.getGrade();
	if (grade > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (grade < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

// Destructors
Bureaucrat::~Bureaucrat()
{
}

// Operators
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &assign) throw (GradeTooHighException, GradeTooLowException)
{
	int	grade;

	grade = assign.getGrade();
	if (grade > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (grade < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade = grade;

	return *this;
}

// Exception classes
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// Getters / Setters
const std::string&	Bureaucrat::getName( void ) const
{
	return _name;
}

int					Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void				Bureaucrat::setGrade(int grade) throw (GradeTooHighException, GradeTooLowException)
{
	if (grade > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (grade < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

// Actions
void	Bureaucrat::promote( void ) throw (GradeTooHighException, GradeTooLowException)
{
	if (_grade - 1  > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (_grade - 1 < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::demote( void ) throw (GradeTooHighException, GradeTooLowException)
{
	if (_grade + 1  > BUREAUCRAT_MAX_GRADE)
		throw GradeTooLowException();
	if (_grade + 1 < BUREAUCRAT_MIN_GRADE)
		throw GradeTooHighException();
	_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(std::exception& e)
	{
		std::cout << _name << " failed to execute " << form.getName() << " form: " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " executed " << form.getName() << std::endl;
}

// Stream operators
std::ostream&	operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.';
	return out;
}
