/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 02:31:56 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <exception>
#include <iostream>
#include <deque>

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
		~Span();

		int		shortestSpan() const;
		int		longestSpan() const;

		void	addNumber(int num);

		template<typename Iter>
		void	addNumbers(Iter begin, Iter end);

	private:
		unsigned int	_max;
		std::deque<int>	_nums;
};

#endif // SPAN_H
