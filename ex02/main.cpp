/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:25 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/27 16:29:43 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "      ShrubberyCreationForm     " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				jimmy("Jimmy", 100);
		ShrubberyCreationForm	form1("Schwarzwald");

		jimmy.signForm(form1);
		jimmy.executeForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "      PresidentialPardonForm    " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				biden("Biden", 1);
		PresidentialPardonForm	form2("some dude");

		biden.signForm(form2);
		biden.executeForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "       RobotomyRequestForm      " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				olaf("Olaf", 45);
		RobotomyRequestForm		form3("Angie");

		olaf.signForm(form3);
		olaf.executeForm(form3);
		olaf.executeForm(form3);
		olaf.executeForm(form3);
		olaf.executeForm(form3);
		olaf.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "    Grade too low to execute    " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				marvin("Marvin", 50);
		RobotomyRequestForm		form3("Mathias");

		marvin.signForm(form3);
		marvin.executeForm(form3);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "     Execute unsigned form      " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				high_performer("High Performer", 1);
		RobotomyRequestForm		form4("Peter");

		high_performer.executeForm(form4);

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

	ShrubberyCreationForm abc("some dude");
	std::cout << abc << std::endl;
	return (0);
}
