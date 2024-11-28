
#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp"

int main()
{
	// Тестирование с std::vector<int>
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 10); // 0, 10, 20, ..., 90

	try
	{
		std::cout << "Searching for 30 in vector: ";
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found " << *it << " at position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 100 in vector: ";
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Found " << *it << " at position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Тестирование с std::list<int>
	std::list<int> lst;
	for (int i = 0; i < 5; ++i)
		lst.push_back(i + 1); // 1, 2, 3, 4, 5

	try
	{
		std::cout << "Searching for 3 in list: ";
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "Found " << *it << " at position " << std::distance(lst.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 6 in list: ";
		std::list<int>::iterator it = easyfind(lst, 6);
		std::cout << "Found " << *it << " at position " << std::distance(lst.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}