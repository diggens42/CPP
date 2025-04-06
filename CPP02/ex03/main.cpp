/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:17:21 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/10 18:36:38 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point p1(3,3);
	std::cout << "Point (3, 3) inside triangle: " << bsp(a, b, c, p1) << std::endl;

	Point p2(10, 10);
	std::cout << "Point (10, 10) outside triangle: " << bsp(a, b, c, p2) << std::endl;

	Point p3(5, 0);
	std::cout << "Point (5, 0)on edge of triangle: " << bsp(a, b, c, p3) << std::endl;

	Point p4(0.1, 0.1);
	std::cout << "Point (0.1, 0.1) close to outside but still inside triangle: " << bsp(a, b, c, p4) << std::endl;

	Point p5(-0.1,-0.1);
	std::cout << "Point (-0.1, -0.1) close to inside but outside of triangle: " << bsp(a, b, c, p5) << std::endl;
	return (0);
}
