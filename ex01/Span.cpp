/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 01:43:55 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max(0), _nums(0)
{
	std::cout << GREY << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N) : _max(N)
{
	std::cout << GREY << "Span param constructor called" << RESET << std::endl;
}

Span::Span(const Span &other)
{
	std::cout << GREY << "Span copy constructor called" << RESET << std::endl;
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Span copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Span::~Span()
{
	std::cout << GREY << "Span destructor called" << RESET << std::endl;
}

void	Span::addNumber(int num)
{
	if (_nums.size() >= _max)
		throw (SpanIsFullException());
	_nums.push_back(num);
}
