/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:55:33 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/16 20:03:13 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
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

	return (0);
}
