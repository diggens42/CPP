/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:10:33 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/03 23:42:35 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class ValueNotFoundException : public std::exception
{
	public:
		const char*	what() const noexcept override
		{
			return("Value not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T& haystack, int needle)
{
	auto iter = std::find(haystack.begin(), haystack.end(), needle);
	if (iter == haystack.end())
		throw (ValueNotFoundException());
	return (iter);
}


#endif // EASYFIND_HPP
