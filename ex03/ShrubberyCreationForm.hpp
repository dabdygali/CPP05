/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:20:42 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:06:54 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SHRUBBERYCREATIONFORM_HPP_
	#define _SHRUBBERYCREATIONFORM_HPP_

	// Custom headers
	#include "AForm.hpp"
	
	// Macros used by code
	#define SHRUBBERYCREATIONFORM_DFT_NAME			"shrubbery creation"
	#define SHRUBBERYCREATIONFORM_DFT_TARGET		"_ShrubberyCreationForm_default_target_"
	#define SHRUBBERYCREATIONFORM_MIN_GRADE			AFORM_MIN_GRADE
	#define SHRUBBERYCREATIONFORM_MAX_GRADE			AFORM_MAX_GRADE
	#define SHRUBBERYCREATIONFORM_DFT_SIGN_GRADE	145
	#define SHRUBBERYCREATIONFORM_DFT_EXEC_GRADE	137
	#define SHRUBBERYCREATIONFORM_DFT_ASCII_TREE	"       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\"

	// Check Macros
	#if SHRUBBERYCREATIONFORM_MAX_GRADE < SHRUBBERYCREATIONFORM_MIN_GRADE ||\
	SHRUBBERYCREATIONFORM_DFT_SIGN_GRADE < SHRUBBERYCREATIONFORM_MIN_GRADE || SHRUBBERYCREATIONFORM_DFT_SIGN_GRADE > SHRUBBERYCREATIONFORM_MAX_GRADE ||\
	SHRUBBERYCREATIONFORM_DFT_EXEC_GRADE < SHRUBBERYCREATIONFORM_MIN_GRADE || SHRUBBERYCREATIONFORM_DFT_EXEC_GRADE > SHRUBBERYCREATIONFORM_MAX_GRADE
		#error "Macros setup wrong"
	#endif

	class ShrubberyCreationForm : public AForm
	{
		private:
			static const std::string	_sName;
			static const int			_sGradeToSign;
			static const int			_sGradeToExecute;
			
			// Constructors
			ShrubberyCreationForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException);

			// Operators
			ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& assign);

			// Actions
			virtual void	performExecution( void ) const;
			
		public:
			// Constructors
			ShrubberyCreationForm(const std::string& target) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);
			ShrubberyCreationForm(const ShrubberyCreationForm& src) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);

			// Destructors
			virtual ~ShrubberyCreationForm();

			// Factory
			static AForm*	newShrubberyCreationForm(const std::string& target);

			// Getters / Setters
			virtual const std::string&	getName( void ) const;
			virtual int					getSignGrade( void ) const;
			virtual int					getExecGrade( void ) const;
	};
	
#endif
