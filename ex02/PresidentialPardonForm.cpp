/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:27:46 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 17:09:49 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5)
{
	std::cout << GREY << "PresidentialPardon default constructor called" << RESET << std::endl;
	setTarget("default");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardon", 25, 5)
{
	std::cout << GREY << "PresidentialPardon param constructor called" << RESET << std::endl;
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << GREY << "PresidentialPardon copy constructor called" << RESET << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		std::cout << GREY << "PresidentialPardon copy assignment operator called" << RESET << std::endl;
		setTarget(other.getTarget());
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREY << "PresidentialPardon destructor called" << RESET << std::endl;
}

void		PresidentialPardonForm::setTarget(const std::string& target)
{
	_target = target;
}
std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by " << executor.getName() << std::endl;
}
