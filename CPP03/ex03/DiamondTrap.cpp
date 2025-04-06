#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
	FragTrap frag_temp;
	ScavTrap scav_temp;

	this->_hp = frag_temp.getHP();
	this->_energy = scav_temp.getEnergy();
	this->_atk = frag_temp.getATK();
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) , _name(name)
{
	FragTrap frag_temp;
	ScavTrap scav_temp;

	this->_hp = frag_temp.getHP();
	this->_energy = scav_temp.getEnergy();
	this->_atk = frag_temp.getATK();

	std::cout << "DiamondTrap named constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
