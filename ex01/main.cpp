/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:00 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/05 16:50:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "       Tests from subject       " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "addNumbers() vector into dequeue" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;

	std::vector<int> numbers = {1, 3, 5, 7, 9};
	Span sp2(5);
	try
	{
		sp2.addNumbers(numbers.begin(), numbers.end());
		unsigned int i = 0;
		while (i < sp2.getMax())
		{
			std::cout << sp2[i] << std::endl;
			i++;
		}
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "  Test exception size too small " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;

	std::deque<int> dequeNumbers = {6, 7, 8, 9, 10};
	Span sp3(4);
	try
	{
		sp3.addNumbers(dequeNumbers.begin(), dequeNumbers.end());
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << " Test not enough nums exception " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
	int	x = 3;
	Span sp4(5);
	try
	{
		sp4.addNumber(x);
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
