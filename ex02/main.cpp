/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:29:23 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/31 00:40:04 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <cassert>

int main()
{
	FragTrap frag("FR4G-TP");
	// Test inherited methods from ClapTrap
	std::cout << "Name: " << frag.getName() << std::endl;
	std::cout << "HP: " << frag.getHP() << std::endl;
	std::cout << "Energy: " << frag.getEnergy() << std::endl;
	std::cout << "Attack: " << frag.getATK() << std::endl;

	// Test inherited functionality
	frag.attack("Enemy");
	frag.takeDamage(30);
	frag.beRepaired(20);

	// Test FragTrap specific method
	frag.highFivesGuys();

	// Create a copy using the copy constructor
	FragTrap frag_copy(frag);

	std::cout << "\nCopy's stats:" << std::endl;
	std::cout << "Name: " << frag_copy.getName() << std::endl;
	std::cout << "HP: " << frag_copy.getHP() << std::endl;

	// Test assignment operator
	FragTrap frag_assigned;
	frag_assigned = frag;

	std::cout << "\nAssigned FragTrap's stats:" << std::endl;
	std::cout << "Name: " << frag_assigned.getName() << std::endl;
	std::cout << "HP: " << frag_assigned.getHP() << std::endl;

	return 0;
}


