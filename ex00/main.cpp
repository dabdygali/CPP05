/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:44:28 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/12 14:50:10 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat	clerk("Stanley", 150);
	std::cout << clerk << std::endl;
	std::cout<< "Trying to demote" << std::endl;
	try
	{
		clerk.demote();	
	}
	catch (std:: exception & e)
	{
		std::cerr << "Exception caught" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout<< "Change grade" << std::endl;
	clerk.setGrade(1);
	std::cout << clerk << std::endl;
	std::cout<< "Trying to promote" << std::endl;
	try
	{
		clerk.promote();	
	}
	catch (std:: exception & e)
	{
		std::cerr << "Exception caught" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout<< "Trying to set grade 1000" << std::endl;
	try
	{
		clerk.setGrade(1000);	
	}
	catch (std:: exception & e)
	{
		std::cerr << "Exception caught" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << clerk << std::endl;
	return EXIT_SUCCESS;
}
