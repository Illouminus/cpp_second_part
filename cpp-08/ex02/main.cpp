// main.cpp
#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
	try
	{
		std::cout << "Creating MutantStack and adding elements..." << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top element: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size after pop: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "Iterating over MutantStack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);

		std::cout << std::endl;

		std::cout << "Additional Tests with std::list:" << std::endl;
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);

		MutantStack<int, std::list<int> > mstackList;
		mstackList.push(10);
		mstackList.push(20);
		mstackList.push(30);
		mstackList.push(40);
		mstackList.push(50);

		std::cout << "Iterating over MutantStack with std::list:" << std::endl;
		MutantStack<int, std::list<int> >::iterator itList = mstackList.begin();
		MutantStack<int, std::list<int> >::iterator iteList = mstackList.end();
		while (itList != iteList)
		{
			std::cout << *itList << std::endl;
			++itList;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}