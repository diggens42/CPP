/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:05:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/01 20:05:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <string>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
		virtual	~Base();
};
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
#endif // BASE_H
