/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:02:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/15 20:31:12 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog();
		void	makeSound() const override;
		Brain*	getBrain() const;
		void	setBrain(Brain* brain);
	private:
		Brain* _brain;
};

#endif // DOG_H
