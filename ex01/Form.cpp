#include "Form.hpp"
#include <iostream>

Form::Form()
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}
