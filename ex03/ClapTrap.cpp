#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : hp(10), energy(10), atk(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hp(10), energy(10), atk(0)
{
	std::cout << "ClapTrap constructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		setName(other.name);
		setHP(other.hp);
		setEnergy(other.energy);
		setATK(other.atk);
		std::cout << "ClapTrap copy assignment operator called ";
		if (!getName().empty())
			std::cout << "for " << getName() << std::endl;
		else
			std::cout << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called ";
	if (!getName().empty())
		std::cout << "for " << getName() << std::endl;
	else
		std::cout << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (getHP() > 0 && getEnergy() > 0)
	{
		std::cout << getName() << " attacks " << target << " and deals " << getATK() << " damage " << std::endl;
		setEnergy(getEnergy() - 1);
	}
	else if (getHP() == 0)
		std::cout << getName() << " can't attack " << target << " because it's technically dead (0 HP)" << std::endl;
	else if (getEnergy() == 0)
		std::cout  << getName() << " can't attack " << target << " because its energy is too low" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (getHP() > amount)
		setHP(getHP() - amount);
	else
		setHP(0);
	std::cout << getName() << " takes " << amount << " damage and now has " << getHP() << " HP" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getHP() > 0 && getEnergy() > 0)
	{
		setHP(getHP() + amount);
		setEnergy(getEnergy() - 1);
		std::cout << getName() << " repairs for " << amount << " HP and has " << getHP() << " HP now" << std::endl;
	}
	else if (getHP() == 0)
		std::cout << getName() << " can't repair because it's technically dead (0 HP)" << std::endl;
	else if (getEnergy() == 0)
		std::cout << getName() << " can't repair because its energy is too low" << std::endl;
}


std::string		ClapTrap::getName() const
{
	return (name);
}

unsigned int	ClapTrap::getHP() const
{
	return (hp);
}

unsigned int	ClapTrap::getEnergy() const
{
	return (energy);
}

unsigned int	ClapTrap::getATK() const
{
	return (atk);
}


void			ClapTrap::setName(const std::string& set_name)
{
	name = set_name;
}

void			ClapTrap::setHP(unsigned int set_hp)
{
	hp = set_hp;
}

void			ClapTrap::setEnergy(unsigned int set_energy)
{
	energy = set_energy;
}

void			ClapTrap::setATK(unsigned int set_atk)
{
	atk = set_atk;
}

