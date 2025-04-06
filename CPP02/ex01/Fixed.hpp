/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:36:43 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/08 20:46:49 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <cstdlib>
class Fixed
{
	private:
		int					_value;
		static const int	_fractBits = 8;
	public:
		Fixed(); //default constructor
		Fixed(const int n); //constructor with int parameter
		Fixed(const float n); //constructor with float parameter
		Fixed(const Fixed& other);// copy constructor
		Fixed& operator=(const Fixed& other); //copy assignemnt operator
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
