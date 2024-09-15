/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:40:28 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/15 20:40:21 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
		std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(std::string idea, int idx)
{
	if (idx < 0 || idx >= 100)
	{
		std::cout << "Brain Idea index too big/low" << std::endl;
		return ;
	}
	_ideas[idx] = idea;
}
std::string	Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cout << "Brain Idea index too big/low" << std::endl;
		return "kein plan";
	}
	return (_ideas[idx]);
}
