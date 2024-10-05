#include "MutantStack.hpp"

MutantStack::MutantStack()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

MutantStack::MutantStack(const MutantStack &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

MutantStack& MutantStack::operator=(const MutantStack &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

MutantStack::~MutantStack()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}
