/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:36:43 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/22 20:43:31 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					value;
		static const int	fractBits;
	public:
		Fixed(); //default constructor
		Fixed(const Fixed& other) // copy constructor
		Fixed& operator=(const Fixed& other); //copy assignemnt operator
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
