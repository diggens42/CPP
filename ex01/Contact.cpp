/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:42:55 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 16:52:21 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
{
	firstname = first;
	lastname = last;
	nickname = nick;
	phonenumber = phone;
	darkest_secret = secret;
}

std::string Contact::get_firstname() const {return firstname;}
std::string Contact::get_lastname() const {return lastname;}
std::string Contact::get_nickname() const {return nickname;}
std::string Contact::get_phonenumber() const {return phonenumber;}
std::string Contact::get_darkestsecret() const {return darkest_secret;}

void Contact::print_contact() const
{
	std::cout << "First Name: " << firstname << std::endl;
	std::cout << "Last Name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phonenumber: " << phonenumber << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
