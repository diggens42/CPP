/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:17:59 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/30 01:15:12 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "--- Testing ClapTrap ---" << std::endl;
	{
		ClapTrap clap1("Clappy");
		ClapTrap clap2;
		ClapTrap clap3(clap1);

		std::cout << "ClapTrap " << clap1.getName() << " stats: HP=" << clap1.getHP()
				<< ", Energy=" << clap1.getEnergy() << ", ATK=" << clap1.getATK() << std::endl;

		clap1.attack("Target");
		clap1.takeDamage(5);
		clap1.beRepaired(3);

		clap2 = clap1;
		std::cout << "ClapTrap " << clap2.getName() << " stats after assignment: HP=" << clap2.getHP()
				<< ", Energy=" << clap2.getEnergy() << ", ATK=" << clap2.getATK() << std::endl;
	}

	std::cout << "\n--- Testing ScavTrap ---" << std::endl;
	{
		ScavTrap scav1("Scavvy");
		ScavTrap scav2;
		ScavTrap scav3(scav1);

		std::cout << "ScavTrap " << scav1.getName() << " stats: HP=" << scav1.getHP()
				<< ", Energy=" << scav1.getEnergy() << ", ATK=" << scav1.getATK() << std::endl;

		scav1.attack("Enemy");
		scav1.takeDamage(30);
		scav1.beRepaired(15);
		scav1.guardGate();

		scav2 = scav1;
		std::cout << "ScavTrap " << scav2.getName() << " stats after assignment: HP=" << scav2.getHP()
				<< ", Energy=" << scav2.getEnergy() << ", ATK=" << scav2.getATK() << std::endl;
	}

	std::cout << "\n--- Testing Inheritance ---" << std::endl;
	{
		ClapTrap* clap_ptr = new ScavTrap("Hybrid");
		clap_ptr->attack("Target");
		delete clap_ptr;
	}

	return 0;
}

