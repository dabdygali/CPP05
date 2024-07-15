/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:39:59 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/12 14:44:38 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BUREAUCRAT_HPP_
	#define _BUREAUCRAT_HPP_

	#include <string>
	#include <iostream>
	#include <exception>

	// Macros used by code
	/* Bureaucrat grande ranks in reverse. The lower the grade higher the
	rank. Highest rank would have grade "1" */
	#define	BUREAUCRAT_DFT_NAME		"_default_name_"
	#define BUREAUCRAT_MIN_GRADE	1
	#define	BUREAUCRAT_MAX_GRADE	150
	#define	BUREAUCRAT_DFT_GRADE	BUREAUCRAT_MAX_GRADE

	// Checking Macros
	#if BUREAUCRAT_MIN_GRADE > BUREAUCRAT_MAX_GRADE || BUREAUCRAT_DFT_GRADE > \
	BUREAUCRAT_MAX_GRADE || BUREAUCRAT_DFT_GRADE < BUREAUCRAT_MIN_GRADE
		#error "Macros setup wrong"
	#endif

	class Bureaucrat
	{
		public:
			// Exception classes
			class	GradeTooHighException : public std::exception
			{
				public:
					virtual const char*	what( void ) const throw(); 
			};
			class	GradeTooLowException : public std::exception
			{
				public:
					virtual const char*	what( void ) const throw();
			};
			
		private:
			const std::string	_name;
			int					_grade;
			
			// Constructors
			Bureaucrat() throw (GradeTooHighException, GradeTooLowException);

			// Operators
			/* Since Bureaucrat has a constant name attribute it will not be 
			changed and keeps same until destrcution */
			Bureaucrat& operator=(const Bureaucrat &assign) throw (GradeTooHighException, GradeTooLowException);
			
		public:
			// Constructors
			Bureaucrat(const std::string &name, int grade) throw (GradeTooHighException, GradeTooLowException);
			Bureaucrat(const Bureaucrat &src) throw (GradeTooHighException, GradeTooLowException);

			// Destructor
			virtual ~Bureaucrat();

			// Getters / Setters
			const std::string&	getName( void ) const;
			int					getGrade( void ) const;
			void				setGrade(int grade) throw (GradeTooHighException, GradeTooLowException);

			// Actions
			void	promote( void ) throw (GradeTooHighException, GradeTooLowException);
			void	demote( void ) throw (GradeTooHighException, GradeTooLowException);

	};

	// Stream operators
	std::ostream&	operator<<(std::ostream& out, const Bureaucrat& rhs);
#endif
