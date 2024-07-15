/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/15 19:15:49 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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

bool PhoneBook::search_contact() const
{
	if (i == 0)
	{
		std::cout << "No contacts in phonebook" << std::endl;
		return (true);
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
		j++;
	}

	int	idx;
	std::cout << "Enter index of contact to display " << std::endl;
	std::cin >> idx;
	if (std::cin.eof())
		return (false);
	if (idx >= 0 && idx < i)
		contacts[idx].print_contact();
	else
		std::cout << "index no bueno" << std::endl;
	return (true);
}

int	main()
{
	PhoneBook phonebook;
	std::string cmd;

	while(1337)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> cmd;

		if (cmd == "ADD")
		{
			Contact new_contact;
			std::string first, last, nick, phone, secret;

			std::cout << "Enter first name 🌚  ";
			std::cin >> first;
			if (first.empty())
				break ;
			std::cout << "Enter last name 🌝  ";
			std::cin >> last;
			if (last.empty())
				break ;
			std::cout << "Enter nick name 🗿  ";
			std::cin >> nick;
			if (nick.empty())
				break ;
			std::cout << "Enter phonenumber 📞  ";
			std::cin >> phone;
			if (phone.empty())
				break ;
			std::cout << "Enter your darkest secret 🍆  ";
			std::cin >> secret;
			if (secret.empty())
				break ;
			new_contact.set_contact(first, last, nick, phone, secret);
			phonebook.add_contact(new_contact);
			std::cout << "Contact added" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			if (!phonebook.search_contact())
				break ;
		}
		else if (cmd == "EXIT" || cmd.empty())
			break ;
		else
			std::cout << "invalid command" << std::endl;
		std::cout << std::endl;
	}
	return (0);
};

