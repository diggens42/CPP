#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>

class MutantStack
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack &other);
		~MutantStack();

	private:

};

#endif // MUTANTSTACK_H
