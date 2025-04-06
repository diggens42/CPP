/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:52:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 19:20:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREY << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << GREY << "Intern copy constructor called" << RESET << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Intern copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << GREY << "Intern destructor called" << RESET << std::endl;
}

AForm*	Intern::createShrubberyRequestForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}
AForm*	Intern::createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	typedef AForm*	(*FormMaker)(const std::string&);

	const char*	formStrings[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormMaker	formMaker[] =
	{
		&Intern::createShrubberyRequestForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	int	i = 0;
	while (i < 3)
	{
		if (formName == formStrings[i])
		{
			AForm* form = formMaker[i](target);
			std::cout << "Intern creates " << formName << std::endl;
			return (form) ;
		}
		i++;
	}
	throw (UnknownFormException());
}

const char*	Intern::UnknownFormException::what() const noexcept
{
	return ("unknown form exception");
}
