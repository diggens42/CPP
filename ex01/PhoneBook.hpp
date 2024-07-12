/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 16:40:05 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

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
