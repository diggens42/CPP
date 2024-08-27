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
			std::cout << "Materia of type " << m->getType() << " equipped to inventory slot " << i << std::endl;
			return ;
		}
		i++;
	}
	std::cout << "Inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= _slots)
	{
		std::cout << "Invalid Index [0 - 3]" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Nothing equipped on inventory slot " << idx << std::endl;
		return ;
	}
	if (_storage_idx == 255)
	{
		std::cout << "Storage is full. Cleaning storage" << std::endl;
		int i = 0;
		while (i < _storage_slots)
		{
			delete _storage[i];
			_storage[i] = NULL;
			i++;
		}
		_storage_idx = 0;
	}
	_storage[_storage_idx] = _inventory[idx];
	_inventory[idx] = NULL;
	_storage_idx++;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _slots)
		std::cout << "Invalid inventory index" << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << "No item equipped on this slot" << std::endl;
	else
		_inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return (_name);
}
