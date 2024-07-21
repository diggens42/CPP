/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:54:36 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/21 21:25:51 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		typedef void	(Harl::*ComplaintFunction)(void);
		struct ComplaintLevel
		{
			std::string			level;
			ComplaintFunction	fn;
		};
		ComplaintLevel levels[4];

	public:
		void	complain(std::string level);
		Harl();
		~Harl();
};

#endif
