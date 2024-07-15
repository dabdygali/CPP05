/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:44:28 by dabdygal          #+#    #+#             */
/*   Updated: 2024/07/15 12:17:14 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat	a("Stanley", 42);
	Form		f("form-101", 42, 42);

	a.signForm(f);
	a.signForm(f);
	return EXIT_SUCCESS;
}
