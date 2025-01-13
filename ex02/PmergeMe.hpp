#ifndef PMERGEME_H
#define PMERGEME_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <chrono>
#include <exception>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int ac, char *av[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		// struct Pair
		// {
		// 	unsigned int	larger;
		// 	unsigned int	smaller;
		// 	size_t			pos;

		// 	bool operator==(const Pair& other) const {
		// 		return larger == other.larger &&
		// 				smaller == other.smaller &&
		// 				pos == other.pos;
		// 	}

		// 	bool operator!=(const Pair& other) const {
		// 		return !(*this == other);
		// 	}

		// 	bool operator<(const Pair& other) const {
		// 		if (larger != other.larger) return larger < other.larger;
		// 		if (smaller != other.smaller) return smaller < other.smaller;
		// 		return pos < other.pos;
		// 	}

		// 	bool operator>(const Pair& other) const {
		// 		return other < *this;
		// 	}

		// 	bool operator<=(const Pair& other) const {
		// 		return !(*this > other);
		// 	}

		// 	bool operator>=(const Pair& other) const {
		// 		return !(*this < other);
		// 	}
		// };

		void						checkInput(int argc, char **argv);

		void						sortVec();
		std::vector<std::pair<unsigned int, unsigned int>>			pairVec(size_t range);
		std::vector<std::pair<unsigned int, unsigned int>>			sortLargerNumsVec(std::vector<std::pair<unsigned int, unsigned int>>& vecPairs);
		void						setPositionVec(const std::vector<unsigned int>& mainchain, std::vector<std::pair<unsigned int, unsigned int>>& pairs);
		std::vector<size_t>			jacobsthalSequenceVec(size_t size);
		size_t						binSearchVec(const std::vector<unsigned int>& mainchain, size_t start, size_t end, unsigned int smallernums);
		std::vector<unsigned int>	binInsertVec(const std::vector<size_t>& jacobsthal, std::vector<std::pair<unsigned int, unsigned int>>& pairs);
		bool						isSortedVec(const std::vector<unsigned int>& sortedvec) const;

		// void						sortDeq();
		// std::deque<Pair>			pairDeq(size_t range);
		// std::deque<unsigned int>	sortLargerNumsDeq(std::deque<Pair>& deqPairs);
		// void						setPositionDeq(const std::deque<unsigned int>& sortedNumbers, std::deque<Pair>& pairs);
		// std::deque<size_t>			jacobsthalSequenceDeq(size_t size);
		// size_t						binSearchDeq(const std::deque<unsigned int>& mainchain, size_t start, size_t end, unsigned int smallernums);
		// void						binInsertDeq(std::deque<unsigned int>& mainchain, const std::deque<size_t>& jacobsthal, std::deque<Pair>& pairs);
		// bool						isSortedDeq(const std::deque<unsigned int>& sortedvec) const;

		void						printResult();

		class TooFewArgsException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class NonNumericArgException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class DuplicateNumbersException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		std::vector<unsigned int>	_unsorted;

		std::vector<unsigned int>	_vec;
		double						_vecTime;

		std::deque<unsigned int>	_deq;
		double						_deqTime;
};

// ./PmergeMe $(awk -v n=3000 -v max=100000 'BEGIN {srand(); for (i = 1; i <= max; i++) nums[i] = i; for (i = 1; i <= n; i++) { j = int(rand() * max) + 1; printf nums[j] " "; nums[j] = nums[max--]; }}')
// ./PmergeMe `jot -r 3000 1 1000`

#endif // PMERGEME_H
