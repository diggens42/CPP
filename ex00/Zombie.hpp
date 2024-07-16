/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:12:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/14 18:22:44 by fwahl            ###   ########.fr       */
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
		~Zombie();
		void	announce();
		Zombie* newZombie(std::string name);
		void	randomChump(std::string name);
};

