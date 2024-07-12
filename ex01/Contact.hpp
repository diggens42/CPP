/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:37:15 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 16:38:44 by fwahl            ###   ########.fr       */
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

		void print_contact() const
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
