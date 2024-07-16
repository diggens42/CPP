/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:12:07 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/14 18:33:09 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	//stack allocated zombie
	Zombie stack("Stack");
	stack.announce();

	//heap allocated zombie
	Zombie* heap = stack.newZombie("Heap");
	heap->announce();

	//randomChump
	stack.randomChump("Random");

	//free heap zombie
	delete heap;

	return 0;
}
