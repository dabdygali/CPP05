/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:39:59 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/17 16:37:36 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _AFORM_HPP_
	#define _AFORM_HPP_

	// Standard libraries
	#include <string>

	// Custom libraries
	#include "Bureaucrat.hpp"

	// Macros used by code
	#define AFORM_DFT_TARGET	"_form_default_target_"
	#define AFORM_DFT_IS_SIGNED	false
	#define AFORM_MIN_GRADE		BUREAUCRAT_MIN_GRADE
	#define AFORM_MAX_GRADE		BUREAUCRAT_MAX_GRADE

	// Check Macros
	#if AFORM_MIN_GRADE > AFORM_MAX_GRADE
		#error "Macros setup wrong"
	#endif
	
	class Bureaucrat;
	
	class AForm
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
			class	FormIsNotSigned : public std::exception
			{
				virtual const char*	what( void ) const throw();
			};
		
		private:
			bool						_is_signed;
			const std::string			_target;
			
			// Constructors
			AForm();

			// Internal utilities
			virtual void	performExecution( void ) const = 0;
			
		protected:
			// Operators
			AForm& operator=(const AForm &assign);

			// Getters / Setters
			void	setIsSigned(bool is_signed);
			
		public:
			// Constructors
			AForm(const std::string& target);
			AForm(const AForm &src);

			// Destructor
			virtual ~AForm();

			// Getters / Setters
			virtual const std::string&	getName( void ) const = 0;
			bool						getIsSigned( void ) const;
			virtual int					getSignGrade( void ) const = 0;
			virtual int					getExecGrade( void ) const = 0;
			const std::string&			getTarget( void ) const;

			// Actions
			void	beSigned(const Bureaucrat& signer) throw (GradeTooLowException, GradeTooHighException, FormAlreadySigned);
			void	execute(Bureaucrat const & executor) const;

	};

	// Stream operators
	std::ostream&	operator<<(std::ostream& out, const AForm& rhs);
#endif
