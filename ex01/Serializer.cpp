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

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
