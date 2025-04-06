/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:17:59 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/28 23:42:52 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap frend("Frend");
	ClapTrap villain("Villain");

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.setATK(2);
	villain.setATK(1);

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.beRepaired(3);
	villain.beRepaired(2);

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.attack("Villain");
	villain.takeDamage(frend.getATK());
	villain.attack("Frend");
	frend.takeDamage(villain.getATK());

	frend.beRepaired(3);
	villain.beRepaired(2);

	frend.beRepaired(3);
	frend.beRepaired(3);
	frend.beRepaired(3);
}

