/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:25 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 15:53:28 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << " Grade high enough to sign&exec " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat	jimmy("Jimmy", 100);
		Form		form("Form A38", 120, 110);

		jimmy.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "  Grade not high enough to sign " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 100);
		Form		form2("Form B38", 99, 100);

		bob.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << " Form constructor grade too low " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Form		form3("Form D38", 151, 99);
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

	Form abc("Form ABC", 44, 55);
	std::cout << abc << std::endl;
}
