#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Serializer::~Serializer()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}
