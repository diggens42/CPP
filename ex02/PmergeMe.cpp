#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(int ac, char *av[])
{
	bool check = checkInput(ac, av);
	if (check == false)
		return ; //add except

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

bool	PmergeMe::checkInput(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "too few args" << std::endl;
		return (false);
	}

	std::set<unsigned int> unique_nums;

	int i = 1;
	while (i < argc)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
			{
				std::cout << "Error: non numeric arg" << std::endl;
				return (false);
			}
			j++;
		}
		unsigned long num;
		try
		{
			num = std::stoul(argv[i]);
			if (num > std::numeric_limits<unsigned int>::max())
			{
				std::cout << "Error: number " << argv[i] << " is out of bounds" << std::endl;
				//add except
				return (false);
			}
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return (false);
		}

		if (!unique_nums.insert(static_cast<unsigned int>(num)).second)
		{
			std::cerr << "Error: duplicate number" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}
