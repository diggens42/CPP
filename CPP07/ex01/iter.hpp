/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:15:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/02 17:47:07 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void	iter(T* array, size_t len, Func ft)
{
	size_t	i = 0;
	while (i < len)
	{
		ft(array[i]);
		i++;
	}

}

template<typename T>
void	printEntry(T const& entry)
{
	std::cout << entry << "   ";
}

template<typename T>
void	squareSomething(T& entry)
{
	entry = entry * entry;
}


#endif // ITER_HPP
