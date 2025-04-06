/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/05 16:47:07 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	setMax(0);
	std::cout << GREY << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N)
{
	setMax(N);
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
		setMax(other.getMax());
		_nums = other._nums;
		std::cout << GREY << "Span copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Span::~Span()
{
	std::cout << GREY << "Span destructor called" << RESET << std::endl;
}


int		Span::shortestSpan() const
{
	if (_nums.size() <= 1)
		throw (NotEnoughNumsException());
	std::deque<int>	sorted_nums = _nums;
	std::sort(sorted_nums.begin(), sorted_nums.end());

	int	shortest_span = std::numeric_limits<int>::max(), curr_span = 0;
	size_t	i = 1;
	while (i < sorted_nums.size())
	{
		curr_span = sorted_nums[i] - sorted_nums[i - 1];
		shortest_span = std::min(shortest_span, curr_span);
		i++;
	}

	return (shortest_span);
}


int		Span::longestSpan() const
{
	if (_nums.size() <= 1)
		throw (NotEnoughNumsException());
	auto [minIter, maxIter] = std::minmax_element(_nums.begin(), _nums.end());

	return (*maxIter - *minIter);
}

void	Span::addNumber(int num)
{
	if (_nums.size() >= getMax())
		throw (SpanCapacityException());
	_nums.push_back(num);
}

unsigned int	Span::getMax() const
{
	return (this->_max);
}

void			Span::setMax(unsigned int n)
{
	this->_max = n;
}

int& Span::operator[](unsigned int idx)
{
	if (idx >= _nums.size())
		throw (std::out_of_range("Index out of range"));
	return (_nums[idx]);
}

const int& Span::operator[](unsigned int index) const
{
	if (index >= _nums.size())
		throw (std::out_of_range("Index out of range"));
	return (_nums[index]);
}
