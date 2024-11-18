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

	private:
		std::vector<unsigned int>	vector;
		std::deque<unsigned int>	deque;

};

#endif // PMERGEME_H
