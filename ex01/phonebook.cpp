/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 16:39:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string cmd;

	while(1337)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT";
		std::cin >> cmd;

		if (cmd == "ADD")
		{
			Contact newContact;
			std::string first;
			std::string last;
			std::string nick;
			std::string phone;
			std::string secret;


		}
		else if (cmd == "SEARCH")
		{

		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "invalid command" << std::endl;
	}
};

