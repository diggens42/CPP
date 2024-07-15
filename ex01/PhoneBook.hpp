/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:36:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/15 19:04:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		i;
		int		oldest;

		std::string truncate(const std::string& string) const;

	public:
		PhoneBook();
		void add_contact(const Contact& contact);
		bool search_contact() const;
};

#endif
