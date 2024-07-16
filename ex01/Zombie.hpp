/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:12:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/16 19:28:19 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	announce();
		void	setName(std::string name);
};
Zombie* zombieHorde( int N, std::string name );
// Zombie* newZombie(std::string name);
// void	randomChump(std::string name);
