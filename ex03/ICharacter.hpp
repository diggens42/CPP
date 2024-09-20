/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:38:34 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/20 13:54:49 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <string>
#include <iostream>

class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		virtual void		setName(std::string const & name) = 0;
		virtual AMateria*	getInventory(int idx) const = 0;
		virtual AMateria*	getStorage(int idx) const = 0;
		virtual void		setStorage(int idx, AMateria *m) = 0;
		virtual int			getStorageIndex() const = 0;
};

#endif // ICHARACTER_H
