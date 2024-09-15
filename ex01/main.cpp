/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:46 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/15 21:04:22 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
// int main(void)
// {
// 	Dog doge;
// 	std::cout << "-------" << std::endl;
// 	Dog doge2(doge);

// 	doge.makeSound();
// 	doge2.makeSound();

// }

int main()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "        Test animal array       " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	const int size = 6;
	Animal* animals[size];

	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();
	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << "--------------------------------" << std::endl;
	std::cout << "        Test brain & ideas      " << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Dog*	snoop_doge = new Dog();
	Dog		doge2;
	snoop_doge->getBrain()->setIdea("eat", 0);
	doge2.getBrain()->setIdea("sleep",0);
	std::cout << "Idea[0] Dog1" << snoop_doge->getBrain()->getIdea(0) <<std::endl;
	std::cout << "Idea[0] Dog2" << doge2.getBrain()->getIdea(0) <<std::endl;

	doge2 = *snoop_doge;
	std::cout << "Idea[0] Dog1" << snoop_doge->getBrain()->getIdea(0) <<std::endl;
	std::cout << "Idea[0] Dog2" << doge2.getBrain()->getIdea(0) <<std::endl;

	delete snoop_doge;
	return 0;
}
