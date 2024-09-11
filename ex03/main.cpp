/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:29:23 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/11 19:28:18 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// int main()
// {
// 	// Test default constructor
// 	DiamondTrap d1;
// 	std::cout << "Default DiamondTrap created" << std::endl;
// 	std::cout << "Name: " << d1.getName() << std::endl;
// 	std::cout << "HP: " << d1.getHP() << std::endl;
// 	std::cout << "Energy: " << d1.getEnergy() << std::endl;
// 	std::cout << "Attack: " << d1.getATK() << std::endl;

// 	// Test named constructor
// 	DiamondTrap d2("Diamond");
// 	std::cout << "Named DiamondTrap created" << std::endl;

// 	std::cout << "Name: " << d2.getName() << std::endl;
// 	std::cout << "HP: " << d2.getHP() << std::endl;
// 	std::cout << "Energy: " << d2.getEnergy() << std::endl;
// 	std::cout << "Attack: " << d2.getATK() << std::endl;

// 	// Test copy constructor
// 	DiamondTrap d3(d2);
// 	std::cout << "Copied DiamondTrap created" << std::endl;

// 	// Test assignment operator
// 	d1 = d2;
// 	std::cout << "Assignment performed" << std::endl;

// 	// Test inherited methods
// 	d2.attack("Target");
// 	d2.takeDamage(20);
// 	d2.beRepaired(10);

// 	// Test FragTrap specific method
// 	d2.highFivesGuys();

// 	// Test ScavTrap specific method
// 	d2.guardGate();

// 	// Test DiamondTrap specific method
// 	d2.whoAmI();

// 	// Test attributes
// 	std::cout << "Name: " << d2.getName() << std::endl;
// 	std::cout << "HP: " << d2.getHP() << std::endl;
// 	std::cout << "Energy: " << d2.getEnergy() << std::endl;
// 	std::cout << "Attack: " << d2.getATK() << std::endl;

// 	return 0;
// }

int main(void)
{
	DiamondTrap abc;
	ClapTrap* pointer = &abc;
    pointer->attack("someone else");
    pointer->takeDamage(4);
    pointer->beRepaired(3);
    std::cout << std::endl;
}
