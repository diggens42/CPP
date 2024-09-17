/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:40:02 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/17 18:01:16 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}
AMateria::AMateria(std::string const & type)
{
	setType(type);
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		setType(other._type);
		std::cout << "AMateria copy assignment operator called" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void	AMateria::setType(std::string const & type)
{
	_type = type;
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "use template called" << std::endl;
}
