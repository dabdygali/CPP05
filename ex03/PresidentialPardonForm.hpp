/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:20:42 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:14:38 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PRESIDENTIALPARDONFORM_HPP_
	#define _PRESIDENTIALPARDONFORM_HPP_

	// Custom headers
	#include "AForm.hpp"
	
	// Macros used by code
	#define PRESIDENTIALPARDONFORM_DFT_NAME			"presidential pardon"
	#define PRESIDENTIALPARDONFORM_DFT_TARGET		"_PresidentialPardonForm_default_target_"
	#define PRESIDENTIALPARDONFORM_MIN_GRADE		AFORM_MIN_GRADE
	#define PRESIDENTIALPARDONFORM_MAX_GRADE		AFORM_MAX_GRADE
	#define PRESIDENTIALPARDONFORM_DFT_SIGN_GRADE	25
	#define PRESIDENTIALPARDONFORM_DFT_EXEC_GRADE	5

	// Check Macros
	#if PRESIDENTIALPARDONFORM_MAX_GRADE < PRESIDENTIALPARDONFORM_MIN_GRADE ||\
	PRESIDENTIALPARDONFORM_DFT_SIGN_GRADE < PRESIDENTIALPARDONFORM_MIN_GRADE || PRESIDENTIALPARDONFORM_DFT_SIGN_GRADE > PRESIDENTIALPARDONFORM_MAX_GRADE ||\
	PRESIDENTIALPARDONFORM_DFT_EXEC_GRADE < PRESIDENTIALPARDONFORM_MIN_GRADE || PRESIDENTIALPARDONFORM_DFT_EXEC_GRADE > PRESIDENTIALPARDONFORM_MAX_GRADE
		#error "Macros setup wrong"
	#endif

	class PresidentialPardonForm : public AForm
	{
		private:
			static const std::string	_sName;
			static const int			_sGradeToSign;
			static const int			_sGradeToExecute;
			
			// Constructors
			PresidentialPardonForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException);

			// Operators
			PresidentialPardonForm&	operator=(const PresidentialPardonForm& assign);

			// Actions
			virtual void	performExecution( void ) const;
			
		public:
			// Constructors
			PresidentialPardonForm(const std::string& target) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);
			PresidentialPardonForm(const PresidentialPardonForm& src) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);

			// Destructors
			virtual ~PresidentialPardonForm();

			// Factory
			static AForm*	newPresidentialPardonForm(const std::string& target);
			
			// Getters / Setters
			virtual const std::string&	getName( void ) const;
			virtual int					getSignGrade( void ) const;
			virtual int					getExecGrade( void ) const;
	};
	
#endif
