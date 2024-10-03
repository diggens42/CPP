/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/03 20:59:00 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class Array
{
	public:
		Array() : _entries(nullptr), _n(0) {}

		explicit Array(unsigned int n) : _entries(new T[n]), _n(n) {}

		Array(const Array& other) : _entries(new T[other._n]), _n(other._n)
		{
			unsigned int	i = 0;
			while (i < _n)
			{
				_entries[i] = other._entries[i];
				i++;
			}
		}

		~Array()
		{
			delete[] _entries;
		}

		Array&		operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _entries;
				_n = other._n;
				_entries = new T[_n];

				unsigned int	i = 0;
				while (i < _n)
				{
					_entries[i] = other._entries[i];
					i++;
				}
			}
			return (*this);
		}

		T&			operator[](unsigned int idx)
		{
			if (idx >= _n)
				throw (std::out_of_range("idx out of range"));
			return (_entries[idx]);
		}

		const T&	operator[](unsigned int idx) const
		{
			if (idx >= _n)
				throw (std::out_of_range("idx out of range"));
			return (_entries[idx]);
		}

		unsigned int	size() const
		{
			return (_n);
		}


	private:
		T*				_entries;
		unsigned int	_n;

};

#endif // ARRAY_HPP
