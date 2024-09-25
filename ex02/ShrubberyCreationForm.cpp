#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	setTarget("default");
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137)
{
	setTarget(target);
	std::cout << "ShrubberyCreationForm param constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		setTarget(other.getTarget());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
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
