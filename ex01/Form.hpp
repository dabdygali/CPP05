/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:39:59 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/12 17:58:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _FORM_HPP_
	#define _FORM_HPP_

	// Standard libraries
	#include <string>

	// Custom libraries
	#include "Bureaucrat.hpp"

	// Macros used by code
	#define	FORM_DFT_NAME		"_form_default_name_"
	#define FORM_DFT_IS_SIGNED	false
	#define FORM_MIN_GRADE		BUREAUCRAT_MIN_GRADE
	#define FORM_MAX_GRADE		BUREAUCRAT_MAX_GRADE
	#define FORM_DFT_SIGN_GRADE	FORM_MIN_GRADE
	#define FORM_DFT_EXEC_GRADE	FORM_MIN_GRADE

	// Check Macros
	#if FORM_MIN_GRADE > FORM_MAX_GRADE || FORM_DFT_SIGN_GRADE > FORM_MAX_GRADE ||\
	FORM_DFT_SIGN_GRADE < FORM_MIN_GRADE || FORM_DFT_EXEC_GRADE > FORM_MAX_GRADE ||\
	FORM_DFT_EXEC_GRADE < FORM_MIN_GRADE
		#error "Macros setup wrong"
	#endif
	
	class Bureaucrat;
	
	class Form
	{
		public:
			// Exception classes
			class	GradeTooHighException : public std::exception
			{
				virtual const char*	what( void ) const throw();
			};
			class	GradeTooLowException : public std::exception
			{
				virtual const char*	what( void ) const throw();
			};
			class	FormAlreadySigned : public std::exception
			{
				virtual const char*	what( void ) const throw();
			};
		
		private:
			const std::string	_name;
			bool				_is_signed;
			const int			_sign_grade;
			const int			_exec_grade;
			
			// Constructors
			Form() throw (GradeTooHighException, GradeTooLowException);

			// Operators
			/* CAUTION: Assigns only "is_signed" status */
			Form& operator=(const Form &assign);

			// Getters / Setters
			void	setIsSigned(bool is_signed);
			
		public:
			// Constructors
			Form(const std::string &name, int sign_grade, int exec_grade) throw (GradeTooHighException, GradeTooLowException);
			Form(const Form &src) throw (GradeTooHighException, GradeTooLowException);

			// Destructor
			virtual ~Form();

			// Getters / Setters
			const std::string&	getName( void ) const;
			bool				getIsSigned( void ) const;
			int					getSignGrade( void ) const;
			int					getExecGrade( void ) const;

			// Actions
			void	beSigned(const Bureaucrat& by_who) throw (GradeTooLowException, GradeTooHighException, FormAlreadySigned);

	};

	// Stream operators
	std::ostream&	operator<<(std::ostream& out, const Form& rhs);
#endif
