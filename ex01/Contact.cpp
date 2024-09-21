/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:42:55 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/21 15:14:05 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
{
	setFirstName(first);
	setLastName(last);
	setNickName(nick);
	setPhoneNumber(phone);
	setDarkestSecret(secret);
}

void Contact::getContact() const
{
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickName() << std::endl;
	std::cout << "Phonenumber: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

std::string Contact::getFirstName() const
{
	return (_firstname);
}
std::string Contact::getLastName() const
{
	return (_lastname);
}
std::string Contact::getNickName() const
{
	return (_nickname);
}
std::string Contact::getPhoneNumber() const
{
	return (_phonenumber);
}
std::string Contact::getDarkestSecret() const
{
	return (_darkestsecret);
}

void		Contact::setFirstName(const std::string& first)
{
	_firstname = first;
}
void		Contact::setLastName(const std::string& last)
{
	_lastname = last;
}
void		Contact::setNickName(const std::string& nick)
{
	_nickname = nick;
}
void		Contact::setPhoneNumber(const std::string& phone)
{
	_phonenumber = phone;
}
void		Contact::setDarkestSecret(const std::string& secret)
{
	_darkestsecret = secret;
}
