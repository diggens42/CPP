/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:12:39 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/01 19:12:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data somedata = {12345, 123.456, "abcdef"};
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "  Raw data before casting   " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Integer: " << somedata.intie << std::endl;
	std::cout << "Double:  " << somedata.doub << std::endl;
	std::cout << "String:  " << somedata.txt << std::endl;
	std::cout << "Adress:  " << &somedata << std::endl;

	uintptr_t	uintptr = Serializer::serialize(&somedata);
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "  Data after serialization  " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "uintptr value: " << uintptr << std::endl;
	std::cout << "Adress:        " << &uintptr << std::endl;

	Data* dataptr =	Serializer::deserialize(uintptr);
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data after deserialization: " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Integer: " << dataptr->intie << std::endl;
	std::cout << "Double:  " << dataptr->doub << std::endl;
	std::cout << "String:  " << dataptr->txt << std::endl;
	std::cout << "Adress:  " << &dataptr << std::endl;

	return(0);
}
