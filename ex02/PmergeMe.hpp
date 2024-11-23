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

		bool	checkInput(int argc, char **argv);

		void	sortVec();
		std::vector<std::pair<unsigned int, unsigned int>>	pairVec();
		std::vector<unsigned int>							sortLargerNumsVec(std::vector<std::pair<unsigned int, unsigned int>>& vecPairs);
		std::vector<unsigned int>							getSmallerNumsVec(const std::vector<std::pair<unsigned int, unsigned int>>& vecPairs);
		std::vector<size_t>									jacobsthalSequenceVec(size_t size);
		void	binaryInsertVec(std::vector<unsigned int>&mainchain, const std::vector<size_t>& jacobsthal, const std::vector<unsigned int>& numstoinsert);

		void	sortDeq();
		std::deque<std::pair<unsigned int, unsigned int>>	pairDeq();

		void	printResult();
	private:
		std::vector<unsigned int>	_unsorted;

		std::vector<unsigned int>							_vec;
		double												_vecTime;

		std::deque<unsigned int>							_deq;
		std::deque<std::pair<unsigned int, unsigned int>>	_deqPairs;
		double												_deqTime;
};

#endif // PMERGEME_H
