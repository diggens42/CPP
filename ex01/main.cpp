/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:15:37 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/16 19:35:25 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int abc = 15;
	Zombie *Horde = zombieHorde(abc, "dude");
	for (int i = 0; i < abc; i++)
		Horde[i].announce();
	// for (int i = 0; i < abc; i++)
	// 	delete(Horde[i]);
	delete[](Horde);
}
