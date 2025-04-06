/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:55:33 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/03 19:34:47 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

// Pointers:
//		used when you want to optionally modify the passed object or allow for null values.
//		used for polymorphic behavior in inheritance hierarchies, allowing for runtime polymorphism.
// References:
//		used when you want to guarantee that the parameter is not null and you always want to work with the original object.
//		used for polymorphism as well, but don't allow for null checks or reassignment.
//		used in iterator implementations for containers.

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Memory address of string variable:  " << &string << std::endl;
	std::cout << "Memory address of string pointer:   " << stringPTR << std::endl;
	std::cout << "Memory address of string reference: " << &stringREF << std::endl;

	std::cout << "Value of string variable:  " << string << std::endl;
	std::cout << "Value of string pointer:   " << *stringPTR << std::endl;
	std::cout << "Value of string reference: " << stringREF << std::endl;

	std::string string2 = "BRAIN THIS IS HI";
	stringPTR= &string2;
	stringREF = string2;

	std::cout << "Memory address of string pointer:   " << stringPTR << std::endl;
	std::cout << "Memory address of string reference: " << &stringREF << std::endl;

	std::cout << "Value of string pointer:   " << *stringPTR << std::endl;
	std::cout << "Value of string reference: " << stringREF << std::endl;

	return (0);
}
