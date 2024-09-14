/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:46 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/14 21:39:58 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
int main(void)
{
	Animal* doge = new Dog();
	Animal* katzer = new Cat();
	Animal* animal = new Animal();

	std::cout << "This animal is of the type " << doge->getType() << " and makes the sound "  << std::endl;
	doge->makeSound();
	std::cout << "This animal is of the type " << katzer->getType() << " and makes the sound " << std::endl;
	katzer->makeSound();
	std::cout << "This animal is of the type " << animal->getType() << " and makes the sound " << std::endl;
	animal->makeSound();
	delete doge;
	delete katzer;
	delete animal;

	WrongAnimal* falscherkatzer = new WrongCat();
	WrongAnimal* wronganimal = new WrongAnimal();


	std::cout << "This animal is of the type " << falscherkatzer->getType() << " and makes the sound " << std::endl;
	falscherkatzer->makeSound();
	std::cout << "This animal is of the type " << wronganimal->getType() << " and makes the sound " << std::endl;
	wronganimal->makeSound();
	delete falscherkatzer;
	delete wronganimal;
}
