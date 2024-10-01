/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:39:31 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/01 20:03:32 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}

Base*	generate(void)
{
	static std::random_device		rd;
	static std::mt19937				gen(rd);
	std::uniform_int_distribution<>	dis(0, 2);

	int res = dis(gen);
	switch (res)
	{
		case (0):
			return (new A());
		case (1):
			return (new B());
		case (2):
			return (new C());
		default:
			return (nullptr);
	}
}
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object type: C" << std::endl;
	else
		std::cout << "Object type: unknown" << std::endl;
}
void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Object type: A" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
		// std::cerr << e.what() << std::endl;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Object type: B" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
		// std::cerr << e.what() << std::endl;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Object type: C" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
		// std::cerr << e.what() << std::endl;
	}

	std::cout << "Object type: unknown" << std::endl;
}
