/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 19:46:01 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <exception>
#include <iostream>
#include <deque>
#include <vector>

class SpanIsFullException : public std::exception
{
	public:
		const char*	what() const noexcept override
		{
			return("Span is full");
		}
};

class NotEnoughNumsException : public std::exception
{
	public:
		const char*	what() const noexcept override
		{
			return("Not enough numbers to calc span");
		}
};

class SpanCapacityException : public std::exception
{
	public:
		const char*	what() const noexcept override
		{
			return("Span capacity exceeeded");
		}
};


class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		int& operator[](unsigned int idx);
		const int& operator[](unsigned int index) const;
		~Span();

		unsigned int	getMax() const;
		void			setMax(unsigned int n);

		int		shortestSpan() const;
		int		longestSpan() const;

		void	addNumber(int num);

		template<typename Iter>
		void	addNumbers(Iter begin, Iter end)
		{
			while (begin != end && _nums.size() < getMax())
			{
				_nums.push_back(*begin);
				++begin;
			}
			if (begin != end)
				throw (SpanCapacityException());
		}

	private:
		unsigned int	_max;
		std::deque<int>	_nums;
};

#endif // SPAN_H
