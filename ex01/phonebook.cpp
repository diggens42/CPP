/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 17:31:58 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : i(0), oldest(0) {}

std::string	PhoneBook::truncate(const std::string& string) const
{
	if (string.length() > 10)
		return (string.substr(0, 9) + ".");
	return (string);
}

void PhoneBook::add_contact(const Contact& contact)
{
	if (i < 8)
	{
		contacts[i] = contact;
		i++;
	}
	else
	{
		contacts[oldest] = contact;
		oldest = (oldest + 1) % 8;
	}
}

void PhoneBook::search_contact() const
{
	if (i == 0)
	{
		std::cout
			<< "No contacts in phonebook" <<
		std::endl;
		return ;
	}
	std::cout
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" <<
	std::endl;

	int	j = 0;
	while (j < i)
	{
		std::cout
			<< std::setw(10) << j << "|"
			<< std::setw(10) << truncate(contacts[j].get_firstname()) << "|"
			<< std::setw(10) << truncate(contacts[j].get_lastname()) << "|"
			<< std::setw(10) << truncate(contacts[j].get_nickname()) << "|" <<
		std::endl;
	}

	int	idx;
	std::cout << "Enter index of contact to display ";
	std::cin >> idx;

	if (idx >= 0 && idx < i)
		contacts[idx].print_contact();
	else
	{
		std::cout
			<< "index no bueno" <<
		std::endl;

	}
}

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

