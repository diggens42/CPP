/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:23:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 17:09:28 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(75), _executeGrade(100)
{
	std::cout << GREY << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << GREY << "AForm named constructor called" << RESET << std::endl;
	if (getSignGrade() < _maxGrade || getExecuteGrade() < _maxGrade)
		throw (GradeTooHighException());
	if (getSignGrade() > _minGrade || getExecuteGrade() > _minGrade)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &other) : _name(other.getName()), _signed(other.isSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << GREY << "AForm copy constructor called" << RESET << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		std::cout << GREY << "AForm copy assignment operator called" << RESET << std::endl;
		_signed = other.isSigned();
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << GREY << "AForm destructor called" << RESET << std::endl;
}

const std::string&	AForm::getName() const
{
	return (_name);
}
bool				AForm::isSigned() const
{
	return (_signed);
}
int					AForm::getSignGrade() const
{
	return (_signGrade);
}
int					AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

void				AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		_signed = true;
	else
		throw (GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("grade is too low");
}

const char*	AForm::SignedExecption::what() const noexcept
{
	return ("Form is already signed");
}

const char*	AForm::NotSignedException::what() const noexcept
{
	return ("Form is not signed");
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", Sign grade: " << form.getSignGrade() << ", Execute grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return (os);
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw (NotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
}
