/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:44:28 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/18 16:46:26 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main( void )
{
	Intern	noob;
	AForm*	ptr;

	ptr = NULL;
	ptr = noob.makeForm("robotomy request", "Stanley");
	if (ptr)
	{
		delete ptr;
		ptr = NULL;
	}
	
	ptr = noob.makeForm("shrubbery creation", "Stanley");
	if (ptr)
	{
		delete ptr;
		ptr = NULL;
	}

	ptr = noob.makeForm("presidential pardon", "Stanley");
	if (ptr)
	{
		delete ptr;
		ptr = NULL;
	}

	ptr = noob.makeForm("something new", "Stanley");
	if (ptr)
	{
		delete ptr;
		ptr = NULL;
	}
	return EXIT_SUCCESS;
}
