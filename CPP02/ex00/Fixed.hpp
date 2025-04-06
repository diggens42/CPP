/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:36:43 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/06 18:44:52 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
		int					_value;
		static const int	_fractBits = 8;
	public:
		Fixed(); //default constructor
		Fixed(const Fixed& other);// copy constructor
		Fixed& operator=(const Fixed& other); //copy assignemnt operator
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
