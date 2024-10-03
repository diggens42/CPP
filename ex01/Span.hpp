/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 01:44:35 by fwahl            ###   ########.fr       */
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

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void	addNumber(int num);

		template<typename Iter>
		void	addNumbers(Iter begin, Iter end);

	private:
		unsigned int	_max;
		std::deque<int>	_nums;
};

#endif // SPAN_H
