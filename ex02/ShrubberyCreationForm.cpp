/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:26:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 17:10:26 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << GREY << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
	setTarget("default");
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << GREY << "ShrubberyCreationForm param constructor called" << RESET << std::endl;
	setTarget(target);
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << GREY << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		std::cout << GREY << "ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
		setTarget(other.getTarget());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREY << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void		ShrubberyCreationForm::setTarget(const std::string& target)
{
	_target = target;
}
std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw (NotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());

	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file.is_open())
		throw std::runtime_error("Unable to create file");

	file << "     *     " << std::endl;
	file << "    * *    " << std::endl;
	file << "   *   *   " << std::endl;
	file << "  *     *  " << std::endl;
	file << " ********* " << std::endl;
	file << "     |     " << std::endl;
}
