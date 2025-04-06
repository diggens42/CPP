#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	setHP(100);
	setEnergy(50);
	setATK(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	setHP(100);
	setEnergy(50);
	setATK(20);
	std::cout << "ScavTrap constructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergy() > 0 && getHP() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " and deals " << getATK() << " damage" << std::endl;
		setEnergy(getEnergy() - 1);
	}
	else if (getHP() == 0)
		std::cout << getName() << " can't attack " << target << " because it's technically dead (0 HP)" << std::endl;
	else if (getEnergy() == 0)
		std::cout  << getName() << " can't attack " << target << " because its energy is too low" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}
