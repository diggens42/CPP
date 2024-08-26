#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("Ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		std::cout << "Ice copy assignment operator called" << std::endl;
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* AMateria::clone() const
{
	return (new Ice());
}
void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}
