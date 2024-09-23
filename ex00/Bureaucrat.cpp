#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName()
{
	return _name;
}
int			Bureaucrat::getGrade()
{
	return _grade;
}
void		Bureaucrat::setGrade(int grade)
{
	_grade = grade;
}

// void		Bureaucrat::setName(std::string name)
// {
// 	_name = name;
// }

void		Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}
void		Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}


// const char*	GradeTooLowException::what() const noexcept
// {

// }
