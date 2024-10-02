/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/02 18:59:29 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY

template <typename T>
class Array
{
	public:
		Array();
		explicit Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();

		T&	operator[](unsigned int idx);
		const T& operator[](unsigned int idx) const;

		unsigned int	size() const;
	private:
		T*				entries;
		unsigned int	count;

};



#include "Array.tpp"

#endif // ARRAY_HPP
