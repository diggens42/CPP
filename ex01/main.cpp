/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:14:41 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/03 21:51:29 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "          Int array         " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	int		int_array[] = {15, 22, 33, 55, 66, 88};
	size_t	int_array_len = sizeof(int_array)/ sizeof(int);
	std::cout << "Original values: " << std::endl;
	iter(int_array, int_array_len, printEntry<int>);
	std::cout << std::endl;
	std::cout << "Squared values:  " << std::endl;
	iter(int_array, int_array_len, squareSomething<int>);
	iter(int_array, int_array_len, printEntry<int>);


	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "        Double array        " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	double	double_array[] = {2.4, 3.6, 4.5, 5.6, 1.8};
	size_t	double_array_len = sizeof(double_array)/ sizeof(double);
	std::cout << "Original values: " << std::endl;
	iter(double_array, double_array_len, printEntry<double>);
	std::cout << std::endl;
	std::cout << "Squared values:  " << std::endl;
	iter(double_array, double_array_len, squareSomething<double>);
	iter(double_array, double_array_len, printEntry<double>);


	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "        String array        " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;

	std::string	str_array[] = {"templates", "are", "kinda", "cool"};
	size_t		str_array_len = sizeof(str_array)/ sizeof(std::string);
	std::cout << "Printing string array: " << std::endl;
	iter(str_array, str_array_len, printEntry<std::string>);

	std::cout << std::endl;
	return (0);
}
