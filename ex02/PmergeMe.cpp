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
	int i = 1;
	while (i < ac)
	{
		unsigned int	num = std::stoul(av[i]);
		_vec.push_back(num);
		_deq.push_back(num);
		i++;
	}
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

void	PmergeMe::sortVec()
{
	_vecPairs = pairVec();

}
std::vector<std::pair<unsigned int, unsigned int>>	PmergeMe::pairVec()
{
	std::vector<std::pair<unsigned int, unsigned int>> vecPairs;

	bool unpaired = (_vec.size() % 2 != 0);
	size_t	i = 0;
	while (i < _vec.size() - (unpaired ? 1 : 0))
	{
		unsigned int	a = _vec[i];
		unsigned int	b = _vec[i + 1];

		if (a > b)
			vecPairs.push_back(std::make_pair(a, b));
		else
			vecPairs.push_back(std::make_pair(b, a));
		i += 2;
	}
	return (vecPairs);
}

void	PmergeMe::sortDeq()
{
	_deqPairs = pairDeq();
}
std::deque<std::pair<unsigned int, unsigned int>>	PmergeMe::pairDeq()
{
	std::deque<std::pair<unsigned int, unsigned int>> deqPairs;

	bool unpaired = (_deq.size() % 2 != 0);
	size_t	i = 0;
	while (i < _deq.size() - (unpaired ? 1 : 0))
	{
		unsigned int	a = _deq[i];
		unsigned int	b = _deq[i + 1];

		if (a > b)
			deqPairs.push_back(std::make_pair(a, b));
		else
			deqPairs.push_back(std::make_pair(b, a));
		i += 2;
	}
	return (deqPairs);
}
