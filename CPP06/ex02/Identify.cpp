#include "Identify.hpp"

Base*	generate(void)
{
	std::random_device				rd;
	std::mt19937					gen(rd());
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
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Object type: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Object type: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
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
		std::cerr << e.what() << std::endl;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Object type: B" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Object type: C" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Object type: unknown" << std::endl;
}
