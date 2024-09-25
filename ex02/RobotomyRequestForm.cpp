#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	setTarget("default");
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45)
{
	setTarget(target);
	std::cout << "RobotomyRequestForm param constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		setTarget(other.getTarget());
		std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
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
