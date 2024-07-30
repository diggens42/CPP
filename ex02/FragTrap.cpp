#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	setHP(100);
	setEnergy(100);
	setATK(30);
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	setHP(100);
	setEnergy(100);
	setATK(30);
	std::cout << "FragTrap constructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}
