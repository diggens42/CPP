/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/02 20:30:53 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array();
		explicit Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array&		operator=(const Array& other);
		T&			operator[](unsigned int idx);
		const T&	operator[](unsigned int idx) const;

		unsigned int	size() const;
	private:
		T*				_entries;
		unsigned int	_n;

};



#include "Array.tpp"

#endif // ARRAY_HPP
