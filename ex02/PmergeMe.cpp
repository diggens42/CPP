#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << GREY << "Default constructor called" << RESET << std::endl;
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
	// std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		// std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	// std::cout << GREY << "Destructor called" << RESET << std::endl;
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

void	PmergeMe::sortVec()
{
	std::chrono::high_resolution_clock::time_point		vecStart;
	std::chrono::high_resolution_clock::time_point		vecEnd;
	unsigned int										unpaired = 0;
	bool												hasUnpaired;
	std::vector<std::pair<unsigned int, unsigned int>>	vecPairs;
	std::vector<unsigned int>							mainchain;
	std::vector<unsigned int>							smallerNumsToInsert;
	std::vector<size_t>									jacobsthalSequence;

	if (_vec.empty())
	{
		_vecTime = 0;
		return ;
	}
	vecStart = std::chrono::high_resolution_clock::now();
	hasUnpaired = (_vec.size() % 2 != 0);
	if (hasUnpaired)
		unpaired = _vec.back();
	vecPairs = pairVec(_vec.size() - hasUnpaired);

	// std::cout << "Pairs: ";
	// for (auto &p : vecPairs) std::cout << "(" << p.first << ", " << p.second << ") ";
	// std::cout << std::endl;

	mainchain.reserve(_vec.size()); // not sure if this makes sense
	mainchain = sortLargerNumsVec(vecPairs);

	std::cout << "mainchain sorted: ";
	for (auto &n : mainchain) std::cout << n << " ";
	std::cout << std::endl;

	smallerNumsToInsert = getSmallerNumsVec(vecPairs);
	jacobsthalSequence = jacobsthalSequenceVec(smallerNumsToInsert.size());
	binaryInsertVec(mainchain, jacobsthalSequence, smallerNumsToInsert);
	if (hasUnpaired)
	{
		auto insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), unpaired);
		mainchain.insert(insertPos, unpaired);
	}
	vecEnd = std::chrono::high_resolution_clock::now();
	_vec = mainchain;
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds> (vecEnd - vecStart).count();
}

std::vector<std::pair<unsigned int, unsigned int>>	PmergeMe::pairVec(size_t range)
{
	std::vector<std::pair<unsigned int, unsigned int>> vecPairs;
	vecPairs.reserve(range / 2);

	size_t	i = 0;
	while (i < range)
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

std::vector<unsigned int>	PmergeMe::sortLargerNumsVec(std::vector<std::pair<unsigned int, unsigned int>>& vecPairs)
{
	if (vecPairs.size() <= 1)
	{
		std::vector<unsigned int>	res;
		if (vecPairs.empty())
			return (res);
		res.push_back(vecPairs[0].first);
		return (res);
	}
	std::vector<unsigned int>	largerNums;
	for (const auto& pair : vecPairs)
		largerNums.push_back(pair.first);

	size_t	middle = largerNums.size() / 2;
	std::vector<std::pair<unsigned int, unsigned int>> leftPairs(vecPairs.begin(), vecPairs.begin() + middle);
	std::vector<std::pair<unsigned int, unsigned int>> rightPairs(vecPairs.begin() + middle, vecPairs.end());

	std::vector<unsigned int> sortedLeftPairs = sortLargerNumsVec(leftPairs);
	std::vector<unsigned int> sortedRightPairs = sortLargerNumsVec(rightPairs);
	std::vector<unsigned int> mergeVec;

	size_t	i = 0;
	size_t	j = 0;
	for (; i < sortedLeftPairs.size() && j < sortedRightPairs.size();)
	{
		if (sortedLeftPairs[i] <= sortedRightPairs[j])
		{
			mergeVec.push_back(sortedLeftPairs[i]);
			i++;
		}
		else
		{
			mergeVec.push_back(sortedRightPairs[j]);
			j++;
		}
	}
	while (i < sortedLeftPairs.size())
	{
		mergeVec.push_back(sortedLeftPairs[i]);
		i++;
	}
	while (j < sortedRightPairs.size())
	{
		mergeVec.push_back(sortedRightPairs[j]);
		j++;
	}
	return (mergeVec);
}

std::vector<unsigned int>	PmergeMe::getSmallerNumsVec(const std::vector<std::pair<unsigned int, unsigned int>>& vecPairs)
{
	std::vector<unsigned int>	smallerNums;
	smallerNums.reserve(_vec.size() / 2);
	auto iter = vecPairs.begin();
	while (iter != vecPairs.end())
	{
		smallerNums.push_back(iter->second);
		iter++;
	}
	return (smallerNums);
}

std::vector<size_t>	PmergeMe::jacobsthalSequenceVec(size_t size)
{
	std::vector<size_t>	jacobsthalSequence;

	if (size <= 1)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(1);

	size_t	prev = 1;
	size_t	cur = 3;
	size_t	next;
	while (cur < size)
	{
		jacobsthalSequence.push_back(cur);
		next = cur * 2 - prev;
		prev = cur;
		cur = next;
	}

	std::vector<size_t>	res;
	size_t	i = 0;
	size_t	j;
	size_t	prev_val;
	while (i < jacobsthalSequence.size())
	{
		j = jacobsthalSequence[i];
		prev_val = (i > 0 ? jacobsthalSequence[i - 1] : 0);
		while (j-- > prev_val)
		{
			if (j + 1 <= size)
				res.push_back(j);
		}
		i++;
	}

	return (res);
}

void	PmergeMe::binaryInsertVec(std::vector<unsigned int>&mainchain, const std::vector<size_t>& jacobsthal, const std::vector<unsigned int>& numstoinsert)
{
	size_t	i = 0;
	while (i < numstoinsert.size())
	{
		size_t	curPos = jacobsthal[i];
		if (curPos >= numstoinsert.size())
		{
			i++;
			continue ;
		}
		auto	insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), numstoinsert[curPos]);
		mainchain.insert(insertPos, numstoinsert[curPos]);
		i++;
	}
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
