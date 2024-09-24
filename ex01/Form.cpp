#include "Form.hpp"
#include <iostream>

Form::Form() : _name("default"), _signed(false), _signGrade(75), _executeGrade(100)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (getSignGrade() < _maxGrade || getExecuteGrade() < _maxGrade)
		throw (GradeTooHighException());
	if (getSignGrade() > _minGrade || getExecuteGrade() > _minGrade)
		throw (GradeTooLowException());
	std::cout << "Form named constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()), _signed(other.isSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other.isSigned();
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

const std::string&	Form::getName() const
{
	return (_name);
}
bool				Form::isSigned() const
{
	return (_signed);
}
int					Form::getSignGrade() const
{
	return (_signGrade);
}
int					Form::getExecuteGrade() const
{
	return (_executeGrade);
}

void				Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		_signed = true;
	else
		throw (GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", Sign grade: " << form.getSignGrade() << ", Execute grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return (os);
}
