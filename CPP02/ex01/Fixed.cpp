/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:06:52 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/08 20:46:31 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const float FLOAT_MAX = 3.40282347e+38f;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	if (n > (INT_MAX >> _fractBits))
	{
		std::cerr << "Int overflow error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	else
		this->_value = n << _fractBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	if (n > roundf(FLOAT_MAX / (1 << _fractBits)))
	{
		std::cerr << "Float overflow error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	else
		this->_value = roundf(n * (1 << _fractBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << _fractBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

