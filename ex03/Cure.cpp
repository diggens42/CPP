#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		std::cout << "Cure copy assignment operator called" << std::endl;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}
AMateria* Cure::clone() const
{
	return (new Cure());
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
