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
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
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
