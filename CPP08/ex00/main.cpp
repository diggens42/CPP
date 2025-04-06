/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:15:48 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 00:16:31 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           Vector           " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::vector<int>	hector = {11, 22, 33, 44, 55, 66, 77, 88, 99};
		auto				vector_iter = easyfind(hector, 33);
		std::cout << "Found " << *vector_iter << " in vector" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}


	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "     Single linked list     " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::forward_list<int>	s_linked_list = {11, 22, 33, 44, 55, 66, 77, 88, 99};
		auto					sll_iter = easyfind(s_linked_list, 44);
		std::cout << "Found " << *sll_iter << " in single linked list" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}


	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "     Double linked list     " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::forward_list<int>	d_linked_list = {11, 22, 33, 44, 55, 66, 77, 88, 99};
		auto					dll_iter = easyfind(d_linked_list, 55);
		std::cout << "Found " << *dll_iter << " in double linked list" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}


	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << " Double ended queue (deque) " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::deque<int>			double_ended_queue = {11, 22, 33, 44, 55, 66, 77, 88, 99};
		auto					deque_iter = easyfind(double_ended_queue, 55);
		std::cout << "Found " << *deque_iter << " in double linked list" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "      Array (std::array)    " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::array<int, 9>			array = {11, 22, 33, 44, 55, 66, 77, 88, 99};
		auto						array_iter = easyfind(array, 55);
		std::cout << "Found " << *array_iter << " in double linked list" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "       Test exception       " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::vector<int>	hector = {11, 22, 33, 44, 55, 66, 77, 88, 99};
		auto				vector_iter = easyfind(hector, 35);
		std::cout << "Found " << *vector_iter << " in vector" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	std::cout << std::endl;

	return (0);
}
