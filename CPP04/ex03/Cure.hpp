/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:39:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/08/28 20:46:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H
#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>
class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif // CURE_H
