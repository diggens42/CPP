/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:34:02 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/02 15:55:29 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T& a, const T& b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T	max(const T& a, const T& b)
{
	return ((a > b) ? a : b);
}

#endif // WHATEVER_HPP
