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

		struct Pair
		{
			unsigned int	larger;
			unsigned int	smaller;
			size_t			pos;
		};

		void						checkInput(int argc, char **argv);

		void						sortVec();
		std::vector<Pair>			pairVec(size_t range);
		std::vector<unsigned int>	sortLargerNumsVec(std::vector<Pair>& vecPairs);
		void						setPositionVec(const std::vector<unsigned int>& mainchain, std::vector<Pair>& pairs);
		std::vector<size_t>			jacobsthalSequenceVec(size_t size);
		size_t	PmergeMe::binSearchVec(const std::vector<unsigned int>& mainchain, size_t start, size_t end, unsigned int smallernums);
		void						binaryInsertVec(std::vector<unsigned int>&mainchain, const std::vector<size_t>& jacobsthal, std::vector<Pair>& pairs);

		void						sortDeq();
		std::deque<Pair>			pairDeq(size_t range);
		std::deque<unsigned int>	sortLargerNumsDeq(std::deque<Pair>& deqPairs);
		void						setPositionDeq(const std::deque<unsigned int>& sortedNumbers, std::deque<Pair>& pairs);
		std::deque<size_t>			jacobsthalSequenceDeq(size_t size);
		void						binaryInsertDeq(std::deque<unsigned int>&mainchain, const std::deque<size_t>& jacobsthal, std::deque<Pair>& pairs);

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

#endif // PMERGEME_H
