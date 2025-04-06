/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:37:15 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/21 14:58:58 by fwahl            ###   ########.fr       */
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
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;

	public:
		void setContact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret);
		void getContact() const;

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		void		setFirstName(const std::string& first);
		void		setLastName(const std::string& last);
		void		setNickName(const std::string& nick);
		void		setPhoneNumber(const std::string& phone);
		void		setDarkestSecret(const std::string& secret);
};

#endif
