/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:12:19 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/03 18:23:34 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiiinzzzZ" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
