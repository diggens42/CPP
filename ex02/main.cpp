/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:47:55 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/01 20:09:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           Test 1           " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	Base* veryrandommuchwow = generate();
	identify(veryrandommuchwow);
	identify(*veryrandommuchwow);

	delete (veryrandommuchwow);
	}
	{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           Test 2           " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	Base* veryrandommuchwow = generate();
	identify(veryrandommuchwow);
	identify(*veryrandommuchwow);

	delete (veryrandommuchwow);
	}
	{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           Test 3           " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	Base* veryrandommuchwow = generate();
	identify(veryrandommuchwow);
	identify(*veryrandommuchwow);

	delete (veryrandommuchwow);
	}
	{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           Test 4           " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	Base* veryrandommuchwow = generate();
	identify(veryrandommuchwow);
	identify(*veryrandommuchwow);

	delete (veryrandommuchwow);
	}
	{
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           Test 5           " << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	Base* veryrandommuchwow = generate();
	identify(veryrandommuchwow);
	identify(*veryrandommuchwow);

	delete (veryrandommuchwow);
	}
	return (0);
}
