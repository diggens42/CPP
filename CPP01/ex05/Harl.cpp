/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:59:02 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/21 21:17:22 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	levels[0].level = "DEBUG";
	levels[0].fn = &Harl::debug;
	levels[1].level = "INFO";
	levels[1].fn = &Harl::info;
	levels[2].level = "WARNING";
	levels[2].fn = &Harl::warning;
	levels[3].level = "ERROR";
	levels[3].fn = &Harl::error;
}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string lvl)
{
	int	i = 0;
	while (i < 4)
	{
		if (levels[i].level == lvl)
		{
			(this->*levels[i].fn)();
			return ;
		}
		i++;
	}
	std::cerr << "Invalid complaint level" << std::endl;
}
