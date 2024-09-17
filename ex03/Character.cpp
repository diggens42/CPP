/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:39:33 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/17 18:03:38 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	int	i = 0;
	while (i < _slots)
	{
		_inventory[i] = nullptr;
		i++;
	}
	i = 0;
	while (i < _storage_slots)
	{
		_storage[i] = nullptr;
		i++;
	}
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character named constructor called" << std::endl;
	int	i = 0;
	while (i < _slots)
	{
		_inventory[i] = nullptr;
		i++;
	}
	i = 0;
	while (i < _storage_slots)
	{
		_storage[i] = nullptr;
		i++;
	}
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called" << std::endl;
	int	i = 0;
	while (i < _slots)
	{
		_inventory[i] = nullptr;
		i++;
	}
	i = 0;
	while (i < _storage_slots)
	{
		_storage[i] = nullptr;
		i++;
	}
	*this = other;
}


Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_storage_idx = other._storage_idx;
		int i = 0;
		while (i < _slots)
		{
			if (_inventory[i] != nullptr)
			{
				delete _inventory[i];
				_inventory[i] = nullptr;
			}
			if (other._inventory[i] != nullptr)
				_inventory[i] = other._inventory[i]->clone();
			i++;
		}
		i = 0;
		while (i < _storage_slots)
		{
			if (_storage[i] != nullptr)
			{
				delete _storage[i];
				_storage[i] = nullptr;
			}
			if (other._storage[i] != nullptr)
				_storage[i] = other._storage[i]->clone();
			i++;
		}
		std::cout << "Character copy assignment operator called" << std::endl;
	}
	return (*this);
}

Character::~Character()
{
	int i = 0;
	while (i < _slots)
	{
		if (_inventory[i] != nullptr)
			delete _inventory[i];
		i++;
	}
	i = 0;
	while (i < _storage_slots)
	{
		if (_storage[i] != nullptr)
			delete _storage[i];
		i++;
	}
	std::cout << "Character destructor called" << std::endl;
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	while (i < _slots)
	{
		if (_inventory[i] == nullptr)
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
	if (_inventory[idx] == nullptr)
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
			_storage[i] = nullptr;
			i++;
		}
		_storage_idx = 0;
	}
	_storage[_storage_idx] = _inventory[idx];
	_inventory[idx] = nullptr;
	_storage_idx++;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _slots)
		std::cout << "Invalid inventory index" << std::endl;
	else if (_inventory[idx] == nullptr)
		std::cout << "No item equipped on this slot" << std::endl;
	else
		_inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return (_name);
}
