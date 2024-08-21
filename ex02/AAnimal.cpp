/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:02:58 by fwahl             #+#    #+#             */
/*   Updated: 2024/08/21 21:12:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		std::cout << "Animal copy assignment operator called" << std::endl;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "Weird animal noise" << std::endl;
}

std::string AAnimal::getType() const
{
	return (type);
}
