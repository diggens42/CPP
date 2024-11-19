#ifndef PMERGEME_H
#define PMERGEME_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
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

		void	sortDeq();
		void	pairDeq();

	private:
		std::vector<unsigned int>							_vector;
		std::vector<std::pair<unsigned int, unsigned int>>	_vecPairs;
		std::deque<unsigned int>	_deque;

};

#endif // PMERGEME_H
