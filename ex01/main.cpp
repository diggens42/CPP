/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:25 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/23 20:07:57 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	// test valid Bureaucrat
	try
	{
		Bureaucrat jimmy("Jimmy", 100);
		std::cout << "" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// test Bureacraut constructor grade too high
	try
	{
		Bureaucrat bob("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test Bureaucrat constructor grade too low
	try
	{
		Bureaucrat marc("Marc", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test increment
	try
	{
		Bureaucrat dude("Dude", 1);
		dude.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test decrement
	try
	{
		Bureaucrat angie("Angie", 150);
		angie.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
