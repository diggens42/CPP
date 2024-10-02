/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:34:02 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/02 16:10:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <utility>

template <typename T>
void	swap(T& a, T& b)
{
	//doesn't create a copy, but transfers ownership of resources (ptr to data is moved, lightweight operation)
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);

	// deep copy, more expensive in time&memory
	// T temp = a;
	// a = b;
	// b = temp;
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
