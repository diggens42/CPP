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
	_unsorted = _vec;
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
	std::chrono::high_resolution_clock::time_point	vecStart = std::chrono::high_resolution_clock::now();
	_vecPairs = pairVec();
	std::vector<unsigned int>	mainchain = sortLargerNumsRecursiveVec();
	std::vector<unsigned int>	smallerNumsToInsert = getSmallerNumsVec();
	std::vector<size_t>			jacobsthalSequence = jacobsthalSequenceVec(smallerNumsToInsert.size());
	binaryInsertVec(mainchain, jacobsthalSequence, smallerNumsToInsert);
	std::chrono::high_resolution_clock::time_point	vecEnd = std::chrono::high_resolution_clock::now();
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds> (vecEnd - vecStart).count();
}

void	PmergeMe::printResult()
{
	std::cout << "Before ";
	for (const auto& num : _unsorted)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << "After ";
	for (const auto& num : _vec)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::vector: " << _deqTime << " us" << std::endl;
}

void	PmergeMe::binaryInsertVec(std::vector<unsigned int>&mainchain, const std::vector<size_t>& jacobsthal, const std::vector<unsigned int>& numstoinsert)
{
	size_t	i = 0;
	while (i < numstoinsert.size())
	{
		size_t	curPos = jacobsthal[i];
		if (curPos >= numstoinsert.size())
			continue ;

		auto	insertPos = std::lower_bound(mainchain.begin(), mainchain.begin() + _vecPairs[curPos].first, numstoinsert[curPos]);
		mainchain.insert(insertPos, numstoinsert[curPos]);
		i++;
	}
}

std::vector<size_t>	PmergeMe::jacobsthalSequenceVec(size_t size)
{
	std::vector<size_t>	jacobsthalSequence;

	if (size == 0)
		return (jacobsthalSequence);
	jacobsthalSequence.reserve(size);
	jacobsthalSequence.push_back(0);
	if (size == 1)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(1);

	size_t	cur = 1;
	size_t	prev = 0;
	size_t	i = 2;
	while (i < size)
	{
		size_t	next = cur + 2 * prev;
		jacobsthalSequence.push_back(next);
		prev = cur;
		cur = next;
		i++;
	}
	return (jacobsthalSequence);
}

std::vector<unsigned int>	PmergeMe::getSmallerNumsVec()
{
	std::vector<unsigned int>	smallerNums;
	auto iter = _vecPairs.begin();
	while (iter != _vecPairs.end())
	{
		smallerNums.push_back(iter->second);
		iter++;
	}
	return (smallerNums);
}

std::vector<unsigned int>	PmergeMe::sortLargerNumsRecursiveVec()
{
	if (_vecPairs.size() <= 1)
	{
		if (_vecPairs.empty())
			return (std::vector<unsigned int>());
		return (std::vector<unsigned int>{_vecPairs[0].first});
	}
	std::vector<unsigned int>	largerNums;
	auto iter = _vecPairs.begin();
	while (iter != _vecPairs.end())
	{
		largerNums.push_back(iter->first);
		iter++;
	}
	std::vector<std::pair<unsigned int, unsigned int>>	pairsCopy = _vecPairs;
	_vecPairs.clear();
	size_t	i = 0;
	while (i < _vecPairs.size())
	{
		if (i + 1 < largerNums.size())
		{
			unsigned int	a = largerNums[i];
			unsigned int	b = largerNums[i + 1];
			if (a > b)
				_vecPairs.push_back(std::make_pair(a, b));
			else
				_vecPairs.push_back(std::make_pair(b, a));
		}
		else
			_vecPairs.push_back(std::make_pair(largerNums[i], 0));
		i += 2;
	}
	std::vector<unsigned int>	largerNumsSorted = sortLargerNumsRecursiveVec();
	_vecPairs = pairsCopy;
	return (largerNumsSorted);
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
