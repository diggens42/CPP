#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}
