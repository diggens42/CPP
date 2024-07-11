/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/11 19:28:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;

	public:
		void set_contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
		{
			firstname = first;
			lastname = last;
			nickname = nick;
			phonenumber = phone;
			darkest_secret = secret;
		}

		std::string get_firstname() const {return firstname;}
		std::string get_lastname() const {return lastname;}
		std::string get_nickname() const {return nickname;}
		std::string get_phonenumber() const {return phonenumber;}
		std::string get_darkestsecret() const {return darkest_secret;}

		void get_contact() const
		{
			std::cout
				<< "First Name: " << get_firstname() <<
			std::endl;

			std::cout
				<< "Last Name: " << get_lastname() <<
			std::endl;

			std::cout
				<< "Nickname: " << get_nickname() <<
			std::endl;

			std::cout
				<< "Phonenumber: " << get_phonenumber() <<
			std::endl;

			std::cout
				<< "Darkest Secret: " << get_darkestsecret() <<
			std::endl;
		}
};

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		i;
		int		oldest;

		std::string truncate(const std::string& string) const
		{
			if (string.length() > 10)
				return (string.substr(0, 9) + ".");
			return (string);
		}

	public:
		PhoneBook() : i(0), oldest(0) {}

		void add_contact(const Contact& contact)
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

		void search_contact() const
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
				contacts[idx].get_contact();
			else
			{
				std::cout
					<< "index no bueno" <<
				std::endl;

			}
		}
};
