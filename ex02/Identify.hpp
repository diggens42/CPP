/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:23:58 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/01 20:33:02 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_H
#define IDENTIFY_H


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>
#include <random>
#include <memory>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);


#endif //IDENTIFY_H
