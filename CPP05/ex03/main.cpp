/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:25 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/28 18:00:23 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
		Intern					intern1;
		std::unique_ptr<AForm>	form1(intern1.makeForm("shrubbery creation", "garden"));

		jimmy.signForm(*form1);
		jimmy.executeForm(*form1);
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
		Intern					intern2;
		std::unique_ptr<AForm>	form2(intern2.makeForm("presidential pardon", "Kevin Spacey"));

		biden.signForm(*form2);
		biden.executeForm(*form2);
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
		Intern					intern3;
		std::unique_ptr<AForm>	form3(intern3.makeForm("robotomy request", "Angelo Merte"));

		olaf.signForm(*form3);
		olaf.executeForm(*form3);
		olaf.executeForm(*form3);
		olaf.executeForm(*form3);
		olaf.executeForm(*form3);
		olaf.executeForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "      Unknown form exception    " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				marvin("Marvin", 22);
		Intern					intern4;
		std::unique_ptr<AForm>	form4(intern4.makeForm("I promise I read the terms&conditions - form", "that dude who reads the terms&conditions"));

		marvin.signForm(*form4);
		marvin.executeForm(*form4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "      Unknown form exception    " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat				matthias("Matthias", 1);
		Intern					intern5;
		std::unique_ptr<AForm>	form5(intern5.makeForm("Can we have your firstborn child form?", "you"));

		matthias.signForm(*form5);
		matthias.executeForm(*form5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
