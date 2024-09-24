#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default")
{
	setGrade(75);
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "Bureaucrat named constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	setGrade(other.getGrade());
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
		//name cannot be reassigned because its const
		setGrade(other.getGrade());
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}
int			Bureaucrat::getGrade() const
{
	return _grade;
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
		throw GradeTooHighException();
	_grade--;
}
void		Bureaucrat::decrementGrade()
{
	if (_grade >= _minGrade)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " , Bureaucrat grade " << bureaucrat.getGrade();
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
