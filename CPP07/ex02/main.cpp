/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/03 21:53:27 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "    Default constructor     " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	Array<int> array1;
	std::cout << "Size of array: " << array1.size() << std::endl;

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "    Parameter constructor   " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	Array<int>	array2(4);
	std::cout << "Size of array: " << array2.size() << std::endl;
	unsigned int	i = 0;
	while (i < array2.size())
	{
		std::cout << array2[i] << std::endl;
		i++;
	}


	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "     Test complex types     " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	Array<std::string>	array3(3);
	array3[0] = "abc";
	array3[1] = "def";
	array3[2] = "ghi";
	std::cout << "Size of array: " << array2.size() << std::endl;

	i = 0;
	while (i < array3.size())
	{
		std::cout << array3[i] << "  ";
		i++;
	}

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "      Test = operator       " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	Array<std::string>	array4;
	array4 = array3;
	i = 0;
	std::cout << "Array 4 values copied from Array 3" << std::endl;
	while (i < array4.size())
	{
		std::cout << array4[i] << "  ";
		i++;
	}

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "    Test copy constuctor    " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	Array<std::string>	array5(array4);
	std::cout << "Array 5 values copied from Array 4" << std::endl;
	i = 0;
	while (i < array5.size())
	{
		std::cout << array5[i] << "  ";
		i++;
	}
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << " Test out of range exception" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Array<int> array6(5);
		std::cout << array6[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
