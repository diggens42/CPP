#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _signed(false), _signGrade(75), _executeGrade(100)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (getSignGrade() < _maxGrade || getExecuteGrade() < _maxGrade)
		throw (GradeTooHighException());
	if (getSignGrade() > _minGrade || getExecuteGrade() > _minGrade)
		throw (GradeTooLowException());
	std::cout << "Form named constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _signed(other.isSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other.isSigned();
		std::cout << "Form copy assignment operator called" << std::endl;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
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

void		AForm::execute(Bureaucrat const & executor)
{

}
