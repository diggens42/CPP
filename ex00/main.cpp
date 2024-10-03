/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:15:48 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/03 23:57:35 by fwahl            ###   ########.fr       */
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

	return (0);
}
