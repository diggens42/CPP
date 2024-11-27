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
// #include <execution>
// #include <algorithm>
// #include <iterator>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int ac, char *av[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void	checkInput(int argc, char **argv);

		struct Pair
		{
			unsigned int	larger;
			unsigned int	smaller;
			size_t			pos;
		};

		void	sortVec();
		std::vector<PmergeMe::Pair>							pairVec(size_t range);
		void												setPosition(const std::vector<unsigned int>& sortedNumbers, std::vector<Pair>& pairs);
		std::vector<unsigned int>							sortLargerNumsVec(std::vector<Pair>& vecPairs);
		std::vector<size_t>									jacobsthalSequenceVec(size_t size);
		void												binaryInsertVec(std::vector<unsigned int>&mainchain, const std::vector<size_t>& jacobsthal, std::vector<Pair>& pairs);

		void	sortDeq();
		std::deque<std::pair<unsigned int, unsigned int>>	pairDeq(size_t range);
		std::deque<unsigned int>							sortLargerNumsDeq(std::deque<std::pair<unsigned int, unsigned int>>& deqPairs);
		std::deque<unsigned int>							getSmallerNumsDeq(const std::deque<std::pair<unsigned int, unsigned int>>& deqPairs);
		std::deque<size_t>									jacobsthalSequenceDeq(size_t size);
		void												binaryInsertDeq(std::deque<unsigned int>&mainchain, const std::deque<size_t>& jacobsthal, const std::deque<unsigned int>& numstoinsert);

		void	printResult();

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

		std::vector<unsigned int>							_vec;
		double												_vecTime;

		std::deque<unsigned int>							_deq;
		double												_deqTime;
};

#endif // PMERGEME_H
