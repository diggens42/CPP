/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:25:55 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/16 20:55:38 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon 		weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon();
};
