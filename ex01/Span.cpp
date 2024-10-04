/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 02:07:19 by fwahl            ###   ########.fr       */
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

int		Span::shortestSpan() const
{
	if (_nums.size() <= 1)
		throw (NotEnoughNumsException());
	std::deque<int>	sorted_nums = _nums;
	std::sort(sorted_nums.begin(), sorted_nums.end());

	int	shortest_span = 1, curr_span = 0;
	size_t	i = 1;
	while (i < sorted_nums.size())
	{
		curr_span = sorted_nums[i] = sorted_nums[i] - sorted_nums[i - 1];
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


