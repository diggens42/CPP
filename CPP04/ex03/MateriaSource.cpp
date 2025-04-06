/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:38:02 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/20 17:45:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	int i = 0;
	while (i < _templateMax)
	{
		_template[i] = nullptr;
		i++;
	}
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	int i = 0;
	while (i < _templateMax)
	{
		if (_template[i] != nullptr)
		{
			delete _template[i];
			_template[i] = nullptr;
		}
		i++;
	}
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		int i = 0;
		while (i < _templateMax)
		{
			if (_template[i] != nullptr)
			{
				delete _template[i];
				_template[i] = nullptr;
			}
			i++;
		}
		i = 0;
		while (i < _templateMax)
		{
			if (other._template[i] != nullptr)
				_template[i] = other._template[i];
			i++;
		}
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	int i = 0;
	while (i < _templateMax)
	{
		if (_template[i] != nullptr)
		{
			delete _template[i];
			_template[i] = nullptr;
		}
		i++;
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while (i < _templateMax)
	{
		if (_template[i] == nullptr)
		{
			_template[i] = m;
			return ;
		}
		i++;
	}
	std::cerr << "Can't add new template because templates are full" << std::endl;
	delete m;
}
AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < _templateMax)
	{
		if (_template[i] != nullptr && _template[i]->getType() == type)
			return _template[i]->clone();
		i++;
	}
	std::cerr << "No matching templates" <<std::endl;
	return (nullptr);
}
