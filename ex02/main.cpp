/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:04:51 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/08 02:03:46 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "       Tests from subject       " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iter it = mstack.begin();
		MutantStack<int>::iter ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "       Tests with std::list     " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;
	}
	{
		MutantStack<std::string, std::list<std::string> > mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");

		std::cout << "Top element: " << mstack.top() << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;

		mstack.pop();
		std::cout << "After pop, top element: " << mstack.top() << std::endl;

		mstack.push("C++");
		mstack.push("is");
		mstack.push("awesome");

		std::cout << std::endl;
		std::cout << "Stack contents:" << std::endl;
		MutantStack<std::string, std::list<std::string> >::iter iter = mstack.begin();
		while (iter != mstack.end())
		{
			std::cout << *iter << std::endl;
			iter++;
		}

		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "     Test reverse iteration     " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;

		MutantStack<std::string, std::list<std::string> >::rev_iter rev_iter = mstack.rbegin();
		while (rev_iter != mstack.rend())
		{
			std::cout << *rev_iter << std::endl;
			rev_iter++;
		}

		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "      Test copy constructor     " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;
		MutantStack<std::string, std::list<std::string> > mstack_copy(mstack);
		std::cout << "Copy size: " << mstack_copy.size() << std::endl;

		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "    Test assignment operator    " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;

		MutantStack<std::string, std::list<std::string> > mstack_assigned;
		mstack_assigned = mstack;
		std::cout << "Assigned size: " << mstack_assigned.size() << std::endl;

	}
	return (0);
}
