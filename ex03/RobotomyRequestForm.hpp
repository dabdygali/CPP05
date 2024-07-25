/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:20:42 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:10:55 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ROBOTOMYREQUESTFORM_HPP_
	#define _ROBOTOMYREQUESTFORM_HPP_

	// Custom headers
	#include "AForm.hpp"
	
	// Macros used by code
	#define ROBOTOMYREQUESTFORM_DFT_NAME		"robotomy request"
	#define ROBOTOMYREQUESTFORM_DFT_TARGET		"_RobotomyRequestForm_default_target_"
	#define ROBOTOMYREQUESTFORM_MIN_GRADE		AFORM_MIN_GRADE
	#define ROBOTOMYREQUESTFORM_MAX_GRADE		AFORM_MAX_GRADE
	#define ROBOTOMYREQUESTFORM_DFT_SIGN_GRADE	72
	#define ROBOTOMYREQUESTFORM_DFT_EXEC_GRADE	45

	// Check Macros
	#if ROBOTOMYREQUESTFORM_MAX_GRADE < ROBOTOMYREQUESTFORM_MIN_GRADE ||\
	ROBOTOMYREQUESTFORM_DFT_SIGN_GRADE < ROBOTOMYREQUESTFORM_MIN_GRADE || ROBOTOMYREQUESTFORM_DFT_SIGN_GRADE > ROBOTOMYREQUESTFORM_MAX_GRADE ||\
	ROBOTOMYREQUESTFORM_DFT_EXEC_GRADE < ROBOTOMYREQUESTFORM_MIN_GRADE || ROBOTOMYREQUESTFORM_DFT_EXEC_GRADE > ROBOTOMYREQUESTFORM_MAX_GRADE
		#error "Macros setup wrong"
	#endif

	class RobotomyRequestForm : public AForm
	{
		private:
			static const std::string	_sName;
			static const int			_sGradeToSign;
			static const int			_sGradeToExecute;
			
			// Constructors
			RobotomyRequestForm() throw (AForm::GradeTooHighException, AForm::GradeTooLowException);

			// Operators
			RobotomyRequestForm&	operator=(const RobotomyRequestForm& assign);

			// Actions
			virtual void	performExecution( void ) const;
			
		public:
			// Constructors
			RobotomyRequestForm(const std::string& target) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);
			RobotomyRequestForm(const RobotomyRequestForm& src) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);

			// Destructors
			virtual ~RobotomyRequestForm();

			// Factory
			static AForm*	newRobotomyRequestForm(const std::string& target);
			// Getters / Setters
			virtual const std::string&	getName( void ) const;
			virtual int					getSignGrade( void ) const;
			virtual int					getExecGrade( void ) const;
	};
	
#endif
