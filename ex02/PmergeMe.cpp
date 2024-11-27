#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(int ac, char *av[])
{
	checkInput(ac, av);
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
	_unsorted = other._unsorted;
	_vec = other._vec;
	_vecTime = other._vecTime;
	_deq = other._deq;
	_deqTime = other._deqTime;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_unsorted = other._unsorted;
		_vec = other._vec;
		_vecTime = other._vecTime;
		_deq = other._deq;
		_deqTime = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	// std::cout << GREY << "Destructor called" << RESET << std::endl;
}

void	PmergeMe::checkInput(int argc, char **argv)
{
	if (argc < 2)
		throw (TooFewArgsException());

	std::set<unsigned int> unique_nums;

	int i = 1;
	while (i < argc)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
				throw(NonNumericArgException());
			j++;
		}

		unsigned long num = std::stoul(argv[i]);
		if (num > std::numeric_limits<unsigned int>::max())
			throw (OutOfBoundsException());
		if (!unique_nums.insert(static_cast<unsigned int>(num)).second)
			throw (DuplicateNumbersException());
		i++;
	}

}

void	PmergeMe::printResult()
{
	std::cout << "Before ";
	for (const auto& num : _unsorted)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << "After vec: ";
	for (const auto& num : _vec)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << "After deq: ";
	for (const auto& num : _deq)
		std::cout << num << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque:  " << _deqTime << " us" << std::endl;
}

//VECTOR

void	PmergeMe::sortVec()
{
	std::chrono::high_resolution_clock::time_point	vecStart;
	std::chrono::high_resolution_clock::time_point	vecEnd;
	unsigned int									unpaired = 0;
	bool											hasUnpaired;
	std::vector<Pair>								vecPairs;
	std::vector<unsigned int>						mainchain;
	std::vector<size_t>								jacobsthalSequence;

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

	mainchain.reserve(_vec.size()); // not sure if this makes sense
	mainchain = sortLargerNumsVec(vecPairs);
	setPosition(mainchain, vecPairs);
	jacobsthalSequence = jacobsthalSequenceVec(vecPairs.size());

	binaryInsertVec(mainchain, jacobsthalSequence, vecPairs);
	if (hasUnpaired)
	{
		auto insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), unpaired);
		mainchain.insert(insertPos, unpaired);
	}
	vecEnd = std::chrono::high_resolution_clock::now();
	_vec = mainchain;
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds> (vecEnd - vecStart).count();
}

std::vector<PmergeMe::Pair>	PmergeMe::pairVec(size_t range)
{
	std::vector<Pair> vecPairs;
	vecPairs.reserve(range / 2);

	size_t	i = 0;
	while (i < range)
	{
		unsigned int	a = _vec[i];
		unsigned int	b = _vec[i + 1];

		if (a > b)
			vecPairs.push_back({a, b, 0});
		else
			vecPairs.push_back({b, a, 0});
		i += 2;
	}
	return (vecPairs);
}

void	PmergeMe::setPosition(const std::vector<unsigned int>& sortedNumbers, std::vector<Pair>& pairs)
{
	for (size_t i = 0; i < sortedNumbers.size(); ++i)
	{
		for (auto& pair : pairs)
		{
			if (pair.larger == sortedNumbers[i])
			{
				pair.pos = i;
				break ;
			}
		}
	}
}

std::vector<unsigned int>	PmergeMe::sortLargerNumsVec(std::vector<Pair>& vecPairs)
{
	if (vecPairs.size() <= 1)
	{
		std::vector<unsigned int>	res;
		if (vecPairs.empty())
			return (res);
		res.push_back(vecPairs[0].larger);
		return (res);
	}
	std::vector<unsigned int>	largerNums;
	for (const auto& pair : vecPairs)
		largerNums.push_back(pair.larger);

	size_t	middle = largerNums.size() / 2;
	std::vector<Pair> leftPairs(vecPairs.begin(), vecPairs.begin() + middle);
	std::vector<Pair> rightPairs(vecPairs.begin() + middle, vecPairs.end());

	std::vector<unsigned int> sortedLeftPairs = sortLargerNumsVec(leftPairs);
	std::vector<unsigned int> sortedRightPairs = sortLargerNumsVec(rightPairs);
	std::vector<unsigned int> mergeVec;

	size_t	i = 0;
	size_t	j = 0;
	while (i < sortedLeftPairs.size() && j < sortedRightPairs.size())
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

std::vector<size_t>	PmergeMe::jacobsthalSequenceVec(size_t size)
{
	std::vector<size_t>	jacobsthalSequence;


	if (size == 0)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(0);
	if (size == 1)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(1);

	size_t	prev = 1;
	size_t	cur = 3;
	size_t	next;
	while (jacobsthalSequence.size() < size)
	{
		jacobsthalSequence.push_back(cur);
		next = cur * 2 - prev;
		prev = cur;
		cur = next;
	}
	return (jacobsthalSequence);
}

void	PmergeMe::binaryInsertVec(std::vector<unsigned int>&mainchain, const std::vector<size_t>& jacobsthal, std::vector<Pair>& pairs)
{
	size_t i = 0;
	while (i < jacobsthal.size())
	{
		if (jacobsthal[i] >= pairs.size())
			break ;
		const auto&	pair = pairs[jacobsthal[i]];
		auto		start = mainchain.begin();
		auto		end	= mainchain.begin() + pair.pos;
		auto		insertPos = std::lower_bound(start, end, pair.smaller);
		size_t		insertIdx = std::distance(mainchain.begin(), insertPos);

		mainchain.insert(insertPos, pair.smaller);

		for (auto& p : pairs)
		{
			if (p.pos >= insertIdx)
				p.pos++;
		}
		i++;
	}
	std::vector<bool>	alreadyInserted(pairs.size(), false);
	i = 0;
	while (i < jacobsthal.size())
	{
		if (jacobsthal[i] < pairs.size())
			alreadyInserted[jacobsthal[i]] = true;
		i++;
	}

	i = 0;
	while (i < pairs.size())
	{
		if (!alreadyInserted[i])
		{
			const auto&	pair = pairs[i];
			auto		start = mainchain.begin();
			auto		end = mainchain.begin() + pair.pos;
			auto		insertPos = std::lower_bound(start, end, pair.smaller);
			size_t		insertIdx = std::distance(mainchain.begin(), insertPos);

			mainchain.insert(insertPos, pair.smaller);

			for (auto& p : pairs)
			{
				if (p.pos >= insertIdx)
					p.pos++;
			}
		}
		i++;
	}
}


void	PmergeMe::sortDeq()
{
	std::chrono::high_resolution_clock::time_point		deqStart;
	std::chrono::high_resolution_clock::time_point		deqEnd;
	unsigned int										unpaired = 0;
	bool												hasUnpaired;
	std::deque<std::pair<unsigned int, unsigned int>>	deqPairs;
	std::deque<unsigned int>							mainchain;
	std::deque<unsigned int>							smallerNumsToInsert;
	std::deque<size_t>									jacobsthalSequence;

	if (_deq.empty())
	{
		_deqTime = 0;
		return ;
	}
	deqStart = std::chrono::high_resolution_clock::now();
	hasUnpaired = (_deq.size() % 2 != 0);
	if (hasUnpaired)
		unpaired = _deq.back();
	deqPairs = pairDeq(_deq.size() - hasUnpaired);
	mainchain = sortLargerNumsDeq(deqPairs);

	smallerNumsToInsert = getSmallerNumsDeq(deqPairs);
	jacobsthalSequence = jacobsthalSequenceDeq(smallerNumsToInsert.size());
	binaryInsertDeq(mainchain, jacobsthalSequence, smallerNumsToInsert);
	if (hasUnpaired)
	{
		auto insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), unpaired);
		mainchain.insert(insertPos, unpaired);
	}
	deqEnd = std::chrono::high_resolution_clock::now();
	_deq = mainchain;
	_deqTime = std::chrono::duration_cast<std::chrono::microseconds> (deqEnd - deqStart).count();
}
std::deque<std::pair<unsigned int, unsigned int>>	PmergeMe::pairDeq(size_t range)
{
	std::deque<std::pair<unsigned int, unsigned int>> deqPairs;

	size_t	i = 0;
	while (i < range)
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

std::deque<unsigned int>	PmergeMe::sortLargerNumsDeq(std::deque<std::pair<unsigned int, unsigned int>>& deqPairs)
{
	if (deqPairs.size() <= 1)
	{
		std::deque<unsigned int>	res;
		if (deqPairs.empty())
			return (res);
		res.push_back(deqPairs[0].first);
		return (res);
	}
	std::deque<unsigned int>	largerNums;
	for (const auto& pair : deqPairs)
		largerNums.push_back(pair.first);

	size_t	middle = largerNums.size() / 2;
	std::deque<std::pair<unsigned int, unsigned int>> leftPairs(deqPairs.begin(), deqPairs.begin() + middle);
	std::deque<std::pair<unsigned int, unsigned int>> rightPairs(deqPairs.begin() + middle, deqPairs.end());

	std::deque<unsigned int> sortedLeftPairs = sortLargerNumsDeq(leftPairs);
	std::deque<unsigned int> sortedRightPairs = sortLargerNumsDeq(rightPairs);
	std::deque<unsigned int> mergeDeq;

	size_t	i = 0;
	size_t	j = 0;
	while (i < sortedLeftPairs.size() && j < sortedRightPairs.size())
	{
		if (sortedLeftPairs[i] <= sortedRightPairs[j])
		{
			mergeDeq.push_back(sortedLeftPairs[i]);
			i++;
		}
		else
		{
			mergeDeq.push_back(sortedRightPairs[j]);
			j++;
		}
	}
	while (i < sortedLeftPairs.size())
	{
		mergeDeq.push_back(sortedLeftPairs[i]);
		i++;
	}
	while (j < sortedRightPairs.size())
	{
		mergeDeq.push_back(sortedRightPairs[j]);
		j++;
	}
	return (mergeDeq);
}

std::deque<unsigned int>	PmergeMe::getSmallerNumsDeq(const std::deque<std::pair<unsigned int, unsigned int>>& deqPairs)
{
	std::deque<unsigned int>	smallerNums;
	auto iter = deqPairs.begin();
	while (iter != deqPairs.end())
	{
		smallerNums.push_back(iter->second);
		iter++;
	}
	return (smallerNums);
}

std::deque<size_t>	PmergeMe::jacobsthalSequenceDeq(size_t size)
{
	std::deque<size_t>	jacobsthalSequence;

	if (size == 0)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(0);
	if (size == 1)
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
	return (jacobsthalSequence);
}

void	PmergeMe::binaryInsertDeq(std::deque<unsigned int>&mainchain, const std::deque<size_t>& jacobsthal, const std::deque<unsigned int>& numstoinsert)
{
	size_t i = 0;
	while (i < jacobsthal.size())
	{
		if (jacobsthal[i] >= numstoinsert.size())
			break ;
		unsigned int	numToInsert = numstoinsert[jacobsthal[i]];
		auto			insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), numToInsert);
		mainchain.insert(insertPos, numToInsert);
		i++;
	}
	std::vector<bool>	alreadyInserted(numstoinsert.size(), false);
	i = 0;
	while (i < jacobsthal.size())
	{
		if (jacobsthal[i] < numstoinsert.size())
			alreadyInserted[jacobsthal[i]] = true;
		i++;
	}

	i = 0;
	while (i < numstoinsert.size())
	{
		if (!alreadyInserted[i])
		{
			unsigned int numToInsert = numstoinsert[i];
			auto insertPos = std::lower_bound(mainchain.begin(), mainchain.end(), numToInsert);
			mainchain.insert(insertPos, numToInsert);
		}
		i++;
	}
}

const char*	PmergeMe::TooFewArgsException::what() const noexcept
{
	return ("Error: too few arguments (usage: ./PmergeMe numbers)");
}


const char*	PmergeMe::NonNumericArgException::what() const noexcept
{
	return ("Error: argument is non-numeric");
}

const char*	PmergeMe::OutOfBoundsException::what() const noexcept
{
	return ("Error: Input numbers are out of bounds (unsigned int max)");
}

const char*	PmergeMe::DuplicateNumbersException::what() const noexcept
{
	return ("Error: Duplicate inout numbers");
}
