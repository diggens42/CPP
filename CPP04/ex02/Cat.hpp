/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:02:29 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/15 21:39:19 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H
#include "AAnimal.hpp"
#include "Brain.hpp"
class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		~Cat();
		void	makeSound() const override;
		Brain*	getBrain() const;
		void	setBrain(Brain* brain);
	private:
		Brain* _brain;
};

#endif // CAT_H
