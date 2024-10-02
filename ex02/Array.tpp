/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:23:01 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/02 20:31:58 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array::Array() : entries(nullptr), count(0)
{
}
template <typename T>
Array::Array(unsigned int n) : _n(n)
{
	entries = new T[size()];
}

template <typename T>
Array::Array(const Array& other)
{
	_n = other.size();
	_entries = new T[size()];

	unsigned int	i = 0;
	while (i < size())
	{
		entries[i] = other.entries[i];
		i++;
	}
}

template <typename T>
~Array::Array()
{
	delete[] _entries;
}

template <typename T>
Array&		Array::operator=(const Array& other)
{
	if (this != other)
	{
		delete[] _entries;
		_n = other.size();
		_entries = new T[size()];

		unsigned int	i = 0;
		while (i < size())
		{
			entries[i] = other.entries[i];
			i++;
		}
	}
	return *this;
}

template <typename T>
T&			Array::operator[](unsigned int idx)
{
	if (idx >= size())
		throw (std::out_of_range("idx out of range"));

}

template <typename T>
const T&	operator[](unsigned int idx) const
{

}

template <typename T>
unsigned int	size() const
{

}
