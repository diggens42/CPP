/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:27:20 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 16:30:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	setTarget("default");
	std::cout << GREY << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45)
{
	setTarget(target);
	std::cout << GREY << "RobotomyRequestForm param constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << GREY << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		setTarget(other.getTarget());
		std::cout << GREY << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREY << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void		RobotomyRequestForm::setTarget(const std::string& target)
{
	_target = target;
}
std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "* drilling noises *" << std::endl;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	int	res = dis(gen);
	if (res == 0)
		std::cout << "Robotomy done by " << executor.getName() << " on " << this->getTarget() << " has failed" << std::endl;
	else
		std::cout << "Robotomy done by " << executor.getName() << " on " << this->getTarget() << " has been successful" << std::endl;
}
