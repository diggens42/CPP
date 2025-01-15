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

	// std::set<unsigned int> unique_nums;

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
		// if (!unique_nums.insert(static_cast<unsigned int>(num)).second)
		// 	throw (DuplicateNumbersException());
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
	// std::cout << "After deq: ";
	// for (const auto& num : _deq)
	// 	std::cout << num << " ";
	// std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << _vecTime << " us" << std::endl;
	// std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque:  " << _deqTime << " us" << std::endl;

	if (isSortedVec(_vec) == true)
		std::cout << "Vec OK" << std::endl;
	else
		std::cout << "Vec not sorted" << std::endl;
	// if (isSortedDeq(_deq) == true)
	// 	std::cout << "Deq OK" << std::endl;
	// else
	// 	std::cout << "Deq not sorted" << std::endl;
}

void	PmergeMe::sortVec()
{
	std::chrono::high_resolution_clock::time_point		vecStart;
	std::chrono::high_resolution_clock::time_point		vecEnd;
	unsigned int										unpaired = 0;
	bool												hasUnpaired;
	std::vector<std::pair<unsigned int, unsigned int>>	vecPairs;
	std::vector<std::pair<unsigned int, unsigned int>>	vecPairsSorted;
	std::vector<unsigned int>							mainchain;
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

	vecPairsSorted.reserve(_vec.size());
	vecPairsSorted = sortLargerNumsVec(vecPairs);

	jacobsthalSequence = jacobsthalSequenceVec(vecPairs.size());

	mainchain = binInsertVec(jacobsthalSequence, vecPairsSorted);
	if (hasUnpaired)
	{
		auto insertPos = binSearchVec(mainchain, 0, mainchain.size(), unpaired);
		mainchain.insert(mainchain.begin() + insertPos, unpaired);
	}
	vecEnd = std::chrono::high_resolution_clock::now();
	_vec = mainchain;
	_vecTime = std::chrono::duration_cast<std::chrono::microseconds> (vecEnd - vecStart).count();
}

std::vector<std::pair<unsigned int, unsigned int>>	PmergeMe::pairVec(size_t range)
{
	std::vector<std::pair<unsigned int, unsigned int>> vecPairs;
	vecPairs.reserve(range / 2 );

	size_t	i = 0;
	while (i < range)
	{
		unsigned int	a = _vec[i];
		unsigned int	b = _vec[i + 1];

		if (a > b)
			vecPairs.push_back({a, b});
		else
			vecPairs.push_back({b, a});
		i += 2;
	}
	return (vecPairs);
}

std::vector<std::pair<unsigned int, unsigned int>>	PmergeMe::sortLargerNumsVec(std::vector<std::pair<unsigned int, unsigned int>>& vecPairs)
{
	if (vecPairs.size() <= 1)
	{
		std::vector<std::pair<unsigned int, unsigned int>>	res;
		if (vecPairs.empty())
			return (res);
		res.push_back(vecPairs[0]);
		return (res);
	}
	std::vector<unsigned int>	largerNums;
	for (const auto& pair : vecPairs)
		largerNums.push_back(pair.first);

	size_t	middle = largerNums.size() / 2;
	std::vector<std::pair<unsigned int, unsigned int>> leftPairs(vecPairs.begin(), vecPairs.begin() + middle);
	std::vector<std::pair<unsigned int, unsigned int>> rightPairs(vecPairs.begin() + middle, vecPairs.end());

	std::vector<std::pair<unsigned int, unsigned int>>	sortedLeftPairs = sortLargerNumsVec(leftPairs);
	std::vector<std::pair<unsigned int, unsigned int>>	sortedRightPairs = sortLargerNumsVec(rightPairs);
	std::vector<std::pair<unsigned int, unsigned int>>	mergeVec;

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

// 0 1 1 3 5 11 21 43 85 171....
std::vector<size_t>	PmergeMe::jacobsthalSequenceVec(size_t size)
{
	std::vector<size_t>	jacobsthalSequence;

	jacobsthalSequence.push_back(0);
	jacobsthalSequence.push_back(1);

	size_t	next;
	while (jacobsthalSequence.back() < size)
	{
		next = jacobsthalSequence[jacobsthalSequence.size() - 1] + 2 * jacobsthalSequence[jacobsthalSequence.size() - 2];
		jacobsthalSequence.push_back(next);
	}

	return (jacobsthalSequence);
}

size_t	PmergeMe::binSearchVec(const std::vector<unsigned int>& mainchain, size_t start, size_t end, unsigned int smallernums)
{
	size_t	mid;

	while (start < end)
	{
		mid = start + (end - start) / 2;

		if (mainchain[mid] > smallernums)
			end = mid;
		else if (smallernums == mainchain[mid])
		{
			start = mid;
			break ;
		}
		else
			start = mid + 1;
	}
	return (start);
}

std::vector<unsigned int>	PmergeMe::binInsertVec(const std::vector<size_t>& jacobsthal, std::vector<std::pair<unsigned int, unsigned int>>& pairs)
{

	int							numsInserted;
	size_t						curIdx;
	size_t						prevIdx;
	std::vector<unsigned int>	mainchain;

	for (auto pair : pairs)
		mainchain.push_back(pair.first);
	mainchain.insert(mainchain.begin(), pairs[0].second);
	numsInserted = 1;

	if (pairs.size() < 2)
		return (mainchain);

	auto	iter = jacobsthal.begin() + 3;
	prevIdx = 0;

	while(iter != jacobsthal.end())
	{
		curIdx = *iter - 1;
		if (curIdx >= pairs.size())
			curIdx = pairs.size() - 1;
		while (curIdx > prevIdx)
		{
			size_t insertIdx = binSearchVec(mainchain, 0, curIdx + numsInserted , pairs[curIdx].second);
			mainchain.insert(mainchain.begin() + insertIdx, pairs[curIdx].second);
			numsInserted++;
			curIdx--;
		}
		prevIdx = *iter - 1;
		iter++;
	}
	return (mainchain);
}

bool	PmergeMe::isSortedVec(const std::vector<unsigned int>& sortedvec) const
{
	size_t	i = 1;
	while (i < sortedvec.size())
	{
		if (sortedvec[i - 1] > sortedvec[i])
			return (false);
		i++;
	}
	return (true);
}

void	PmergeMe::sortDeq()
{
	std::chrono::high_resolution_clock::time_point		deqStart;
	std::chrono::high_resolution_clock::time_point		deqEnd;
	unsigned int										unpaired = 0;
	bool												hasUnpaired;
	std::deque<std::pair<unsigned int, unsigned int>>	deqPairs;
	std::deque<std::pair<unsigned int, unsigned int>>	deqPairsSorted;
	std::deque<unsigned int>							mainchain;
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
	deqPairsSorted = sortLargerNumsDeq(deqPairs);
	jacobsthalSequence = jacobsthalSequenceDeq(deqPairs.size());
	mainchain = binInsertDeq(jacobsthalSequence, deqPairs);
	if (hasUnpaired)
	{
		auto insertPos = binSearchDeq(mainchain, 0, mainchain.size(), unpaired);
		mainchain.insert(mainchain.begin() + insertPos, unpaired);
	}
	deqEnd = std::chrono::high_resolution_clock::now();
	_deq = mainchain;
	_deqTime = std::chrono::duration_cast<std::chrono::microseconds> (deqEnd - deqStart).count();
}

std::deque<std::pair<unsigned int, unsigned int>>	PmergeMe::pairDeq(size_t range)
{
	std::deque<std::pair<unsigned int, unsigned int>>	deqPairs;

	size_t	i = 0;
	while (i < range)
	{
		unsigned int	a = _deq[i];
		unsigned int	b = _deq[i + 1];

		if (a > b)
			deqPairs.push_back({a, b});
		else
			deqPairs.push_back({b, a});
		i += 2;
	}
	return (deqPairs);
}

std::deque<std::pair<unsigned int, unsigned int>>	PmergeMe::sortLargerNumsDeq(std::deque<std::pair<unsigned int, unsigned int>>& deqPairs)
{
	if (deqPairs.size() <= 1)
	{
		std::deque<std::pair<unsigned int, unsigned int>>	res;
		if (deqPairs.empty())
			return (res);
		res.push_back(deqPairs[0]);
		return (res);
	}
	std::deque<unsigned int>	largerNums;
	for (const auto& pair : deqPairs)
		largerNums.push_back(pair.first);

	size_t	middle = largerNums.size() / 2;
	std::deque<std::pair<unsigned int, unsigned int>>	leftPairs(deqPairs.begin(), deqPairs.begin() + middle);
	std::deque<std::pair<unsigned int, unsigned int>>	rightPairs(deqPairs.begin() + middle, deqPairs.end());

	std::deque<std::pair<unsigned int, unsigned int>>	sortedLeftPairs = sortLargerNumsDeq(leftPairs);
	std::deque<std::pair<unsigned int, unsigned int>>	sortedRightPairs = sortLargerNumsDeq(rightPairs);
	std::deque<std::pair<unsigned int, unsigned int>>	mergeDeq;

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

std::deque<size_t>	PmergeMe::jacobsthalSequenceDeq(size_t size)
{
	std::deque<size_t>	jacobsthalSequence;

	jacobsthalSequence.push_back(0);
	jacobsthalSequence.push_back(1);

	size_t	next;
	while (jacobsthalSequence.back() < size)
	{
		next = jacobsthalSequence[jacobsthalSequence.size() - 1] + 2 * jacobsthalSequence[jacobsthalSequence.size() - 2];
		jacobsthalSequence.push_back(next);
	}
	return (jacobsthalSequence);
}

size_t	PmergeMe::binSearchDeq(const std::deque<unsigned int>& mainchain, size_t start, size_t end, unsigned int smallernums)
{
	size_t	mid;

	while (start < end)
	{
		mid = start + (end - start) / 2;

		if (mainchain[mid] >= smallernums)
			end = mid;
		else if (smallernums == mainchain[mid])
		{
			start = mid;
			break ;
		}
		else
			start = mid + 1;
	}
	return (start);
}


std::deque<unsigned int>	PmergeMe::binInsertDeq(const std::deque<size_t>& jacobsthal, std::deque<std::pair<unsigned int, unsigned int>>& pairs)
{
	int							numsInserted;
	size_t						curIdx;
	size_t						prevIdx;
	std::deque<unsigned int>	mainchain;

	for (auto pair : pairs)
		mainchain.push_back(pair.first);
	mainchain.insert(mainchain.begin(), pairs[0].second);
	numsInserted = 1;

	if (pairs.size() < 2)
		return (mainchain);

	auto	iter = jacobsthal.begin() + 3;
	prevIdx = 0;

	while(iter != jacobsthal.end())
	{
		curIdx = *iter - 1;
		if (curIdx >= pairs.size())
			curIdx = pairs.size() - 1;
		while (curIdx > prevIdx)
		{
			size_t insertIdx = binSearchDeq(mainchain, 0, curIdx + numsInserted , pairs[curIdx].second);
			mainchain.insert(mainchain.begin() + insertIdx, pairs[curIdx].second);
			numsInserted++;
			curIdx--;
		}
		prevIdx = *iter - 1;
		iter++;
	}
	return (mainchain);
}

bool	PmergeMe::isSortedDeq(const std::deque<unsigned int>& sortedvec) const
{
	size_t	i = 1;
	while (i < sortedvec.size())
	{
		if (sortedvec[i - 1] > sortedvec[i])
			return (false);
		i++;
	}
	return (true);
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
