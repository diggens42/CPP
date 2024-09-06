/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:17:21 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/26 00:18:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // Test case 1: Point inside the triangle
    Point p1(3, 3);
    std::cout << "Test case 1 - Point inside: " << bsp(a, b, c, p1) << std::endl; // Expected output: True (1)

    // Test case 2: Point outside the triangle
    Point p2(10, 10);
    std::cout << "Test case 2 - Point outside: " << bsp(a, b, c, p2) << std::endl; // Expected output: False (0)

    // Test case 3: Point on the edge of the triangle
    Point p3(5, 0);
    std::cout << "Test case 3 - Point on edge: " << bsp(a, b, c, p3) << std::endl; // Expected output: False (0)

    // Test case 4: Point is a vertex of the triangle
    Point p4(0, 0);
    std::cout << "Test case 4 - Point is vertex: " << bsp(a, b, c, p4) << std::endl; // Expected output: False (0)

    // Test case 5: Point on an extended line of the edge but not on the triangle
    Point p5(15, 0);
    std::cout << "Test case 5 - Point on extended edge: " << bsp(a, b, c, p5) << std::endl; // Expected output: False (0)

    // Test case 6: Point very close to but inside the triangle
    Point p6(0.1, 0.1);
    std::cout << "Test case 6 - Point close to inside: " << bsp(a, b, c, p6) << std::endl; // Expected output: True (1)

    // Test case 7: Point very close to but outside the triangle
    Point p7(-0.1, -0.1);
    std::cout << "Test case 7 - Point close to outside: " << bsp(a, b, c, p7) << std::endl; // Expected output: False (0)

    return 0;
}
