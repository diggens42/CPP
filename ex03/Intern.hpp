/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:53:05 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/27 20:10:46 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target);

		class UnknownFormException : public std::exception
		{
			const char*	what() const noexcept override;
		};
	private:
		static AForm*	createShrubberyRequestForm(const std::string& target);
		static AForm*	createRobotomyRequestForm(const std::string& target);
		static AForm*	createPresidentialPardonForm(const std::string& target);
};

#endif // INTERN_H
