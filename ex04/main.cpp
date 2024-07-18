/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:27:35 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/18 19:02:55 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

int main (int argc, char **argv)
{
	std::string	filename;
	std::string	string1;
	std::string	string2;
	if (argc != 4)
	{
		std::cerr << "invalid args (<filename> <s1> <s2>)" << std::endl;
		return (1);
	}
	filename = argv[1];
	string1 = argv[2];
	string2 = argv[3];
	ReplaceFile replace_file(filename, string1, string2);
	try
	{
		replace_file.replacing();
		std::cout << "Replacement complete" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return(0);
}
