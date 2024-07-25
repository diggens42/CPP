/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:36:43 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/25 20:45:43 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractBits = 8;
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

		//comparison ops
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		//arithemtic ops
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		//increment/decrement ops
		Fixed&	operator++(); //pre
		Fixed	operator++(int); //post
		Fixed&	operator--(); //pre
		Fixed	operator--(int); //post

		static	Fixed& min(Fixed& a, Fixed& b);
		static const	Fixed& min(const Fixed& a, const Fixed& b);
		static	Fixed& max(Fixed& a, Fixed& b);
		static const	Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
