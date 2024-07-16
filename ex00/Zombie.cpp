/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:12:19 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/16 18:28:04 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiiinzzzZ" << std::endl;
}
