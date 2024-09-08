/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:04:43 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/06 20:54:53 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	triangleArea(const Point& p1, const Point& p2, const Point& p3)
{
	return (((p2.getX() - p1.getX()) * (p3.getY() - p1.getY())) -
		((p3.getX() - p1.getX()) * (p2.getY() - p1.getY()))) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate the signed area of the main triangle
	Fixed mainArea = triangleArea(a, b, c);

	// Calculate signed areas of three triangles formed by the point and two vertices of the main triangle
	Fixed area1 = triangleArea(point, a, b);
	Fixed area3 = triangleArea(point, c, a);
	Fixed area2 = triangleArea(point, b, c);

    // Check if the point is on any edge or vertex
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;

	bool sameSign = (mainArea > 0 && area1 > 0 && area2 > 0 && area3 > 0) ||
					(mainArea < 0 && area1 < 0 && area2 < 0 && area3 < 0);

	return (sameSign);
}
