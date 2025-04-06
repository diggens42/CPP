/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:25 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 15:51:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "        Valid bureaucrat        " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat jimmy("Jimmy", 100);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "         Grade too high         " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat bob("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "         Grade too low          " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat marc("Marc", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "           Increment            " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat dude("Dude", 1);
		dude.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "           Decrement            " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat angie("Angie", 150);
		angie.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "           << operator          " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	Bureaucrat	bureaucrat("Obama", 123);
	std::cout << bureaucrat << std::endl;

	return (0);
}
