/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:39:12 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 17:08:56 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
	std::cout << GREY << "Bureaucrat default constructor called" << RESET << std::endl;
	setGrade(75);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << GREY << "Bureaucrat named constructor called" << RESET  << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	std::cout << GREY<< "Bureaucrat copy constructor called" << RESET  << std::endl;
	setGrade(other.getGrade());
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Bureaucrat copy assignment operator called" << RESET  << std::endl;
		//name cannot be reassigned because its const
		setGrade(other.getGrade());
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREY << "Bureaucrat destructor called" << RESET  << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}
int			Bureaucrat::getGrade() const
{
	return (_grade);
}
void		Bureaucrat::setGrade(int grade)
{
	if (grade < _maxGrade)
		throw (GradeTooHighException());
	else if (grade > _minGrade)
		throw (GradeTooLowException());
	_grade = grade;
}

void		Bureaucrat::incrementGrade()
{
	if (_grade <= _maxGrade)
		throw (GradeTooHighException());
	_grade--;
}
void		Bureaucrat::decrementGrade()
{
	if (_grade >= _minGrade)
		throw (GradeTooLowException());
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade too low exception");
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade too high exception");
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
