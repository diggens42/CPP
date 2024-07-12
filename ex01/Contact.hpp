/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:37:15 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 16:54:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

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
		void set_contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret);

		std::string get_firstname() const;
		std::string get_lastname() const;
		std::string get_nickname() const;
		std::string get_phonenumber() const;
		std::string get_darkestsecret() const;

		void print_contact() const;
};

#endif
