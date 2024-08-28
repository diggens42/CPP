/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:40:02 by fwahl             #+#    #+#             */
/*   Updated: 2024/08/28 20:48:08 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
AMateria::AMateria()
{
	std::cout << "Materia default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Materia copy constructor called" << std::endl;
}
AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "Materia type constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		std::cout << "Materia copy assignment operator called" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "use template called" << std::endl;
}
