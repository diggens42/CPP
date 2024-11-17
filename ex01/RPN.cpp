#include "RPN.hpp"

RPN::RPN()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}
