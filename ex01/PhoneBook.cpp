/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/21 17:23:05 by fwahl            ###   ########.fr       */
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

void PhoneBook::addContact(const Contact& contact)
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

bool PhoneBook::searchContact() const
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
			<< std::setw(10) << truncate(contacts[j].getFirstName()) << "|"
			<< std::setw(10) << truncate(contacts[j].getLastName()) << "|"
			<< std::setw(10) << truncate(contacts[j].getNickName()) <<
		std::endl;
		j++;
	}

	int	idx;
	std::cout << "Enter index of contact to display: ";
	while (!(std::cin >> idx))
	{
		if (std::cin.eof())
			return (false);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a number: ";
	}
	std::cout << std::endl;
	if (idx >= 0 && idx < 8 && idx < i)
		contacts[idx].getContact();
	else
		std::cout << "Invalid index." << std::endl;
	return (true);
}


bool	readStrToVar(std::string& var)
{
	while (true)
	{
		std::getline(std::cin, var);

		if (std::cin.eof())
		{
			std::cout << "EOF detected";
			return (false);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please try again";
		}
		else if (var.empty())
		{
			std::cout << "Input can't be empty, please try again: ";
		}
		else
			break ;
	}
	std::cout << std::endl;
	return (true);
}

int main(void)
{
	PhoneBook phonebook;

	std::string	cmd;

	while (true)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		if (!readStrToVar(cmd))
			break ;
		if (cmd == "ADD")
		{
			Contact	newcontact;

			std::string first;
			std::cout << "Enter firstname: ";
			if (!readStrToVar(first))
				break ;

			std::string last;
			std::cout << "Enter lastname: ";
			if (!readStrToVar(last))
				break ;

			std::string nick;
			std::cout << "Enter nickname: ";
			if (!readStrToVar(nick))
				break ;

			std::string phone;
			std::cout << "Enter phonenumber: ";
			if (!readStrToVar(phone))
				break ;

			std::string secret;
			std::cout << "Enter your darkest secret: ";
			if (!readStrToVar(secret))
				break ;

			newcontact.setContact(first, last, nick, phone, secret);
			phonebook.addContact(newcontact);
			std::cout << "New contact added to phonebook" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			if (!phonebook.searchContact())
				break ;
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command, please try again" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}

