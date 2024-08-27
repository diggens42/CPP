#include "Character.hpp"
#include <iostream>

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character named constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		std::cout << "Character copy assignment operator called" << std::endl;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	while (i < _slots)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Materia of type " << m->getType() << " equipepd to inventory slot " << i + 1 << std::endl;
			return ;
		}
		i++;
	}
	std::cout << "Inventory is full" << std::endl;
}
