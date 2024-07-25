/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:44:28 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/17 16:33:48 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	Bureaucrat	president("president", 1);
	Bureaucrat	director("director", 40);
	Bureaucrat	manager("manager", 100);
	Bureaucrat	assistant("assistant", 130);
	
	ShrubberyCreationForm	a("Stanley");
	RobotomyRequestForm		b("Stanley");
	PresidentialPardonForm	c("Stanley");

	try { assistant.signForm(a);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { assistant.signForm(b);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { assistant.signForm(c);} catch(std::exception& e){ std::cout << e.what() << std::endl; }

	std::cout << std::endl << "--------------------------------------" << std::endl << std::endl;
	
	try { president.signForm(a);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { president.signForm(b);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { president.signForm(c);} catch(std::exception& e){ std::cout << e.what() << std::endl; }

	std::cout << std::endl << "--------------------------------------" << std::endl << std::endl;

	try { assistant.executeForm(a);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { assistant.executeForm(b);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { assistant.executeForm(c);} catch(std::exception& e){ std::cout << e.what() << std::endl; }

	std::cout << std::endl << "--------------------------------------" << std::endl << std::endl;

	try { president.executeForm(a);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { president.executeForm(b);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	try { president.executeForm(c);} catch(std::exception& e){ std::cout << e.what() << std::endl; }
	
	return EXIT_SUCCESS;
}
