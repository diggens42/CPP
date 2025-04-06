/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:26:13 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/04 18:36:13 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type)
{
}

Weapon::~Weapon() {}

std::string Weapon::getType() const
{
	return(_type);
}

void	Weapon::setType(const std::string& type)
{
	this->_type = type;
}
