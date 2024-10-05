#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator				iter;
		typedef typename Container::const_iterator			const_iter;
		typedef typename Container::reverse_iterator		rev_iter;
		typedef typename Container::const_reverse_iterator	const_rev_iter;

		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack<T, Container>& src) : std::stack<T, Container>(src) {}
		MutantStack& operator=(const MutantStack<T, Container>& other)
		{
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return (*this);
		}
		~MutantStack() {}

		iter			begin()		{return (this->c.begin());}
		iter			end()		{return (this->c.end());}
		const_iter		begin()		{return (this->c.begin());}
		const_iter		end()		{return (this->c.end());}

		rev_iter		rbegin()	{return (this->c.rbegin());}
		rev_iter		rend()		{return (this->c.rend());}
		const_rev_iter	rbegin()	{return (this->c.rbegin());}
		const_rev_iter	rend()		{return (this->c.rend());}

};

#endif // MUTANTSTACK_H
