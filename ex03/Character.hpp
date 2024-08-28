/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:39:20 by fwahl             #+#    #+#             */
/*   Updated: 2024/08/28 20:44:55 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const & name);
		Character(const Character &other);
		Character& operator=(const Character &other);
		~Character();

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		std::string const & getName() const;

	private:
		std::string			_name;
		static const int	_slots = 4;
		static const int	_storage_slots = 256;
		int					_storage_idx;
		AMateria*			_inventory[_slots];
		AMateria*			_storage[_storage_slots];

};

#endif // CHARACTER_H
