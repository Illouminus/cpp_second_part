// main.cpp
#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main()
{
	std::cout << "Test 1: Basic Functionality" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 14

		// Here we try to add one more number than the maximum size
		sp.addNumber(20);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Test 2: Adding Numbers via Range of Iterators" << std::endl;
	try
	{
		Span sp = Span(10);
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		sp.addNumbers(vec.begin(), vec.end());
		sp.addNumber(10);
		sp.addNumber(20);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 1
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 19

		// Here we try to add more numbers than the maximum size
		std::list<int> lst;
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);
		lst.push_back(60);
		lst.push_back(70);
		sp.addNumbers(lst.begin(), lst.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Test 3: Large Dataset" << std::endl;
	try
	{
		unsigned int largeSize = 10000;
		Span sp = Span(largeSize);
		for (unsigned int i = 0; i < largeSize; ++i)
		{
			sp.addNumber(i);
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected 1
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	// Expected 9999
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Test 4: Not Enough Numbers" << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Here we expect an exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Test 5: Initialize Containers Without Initializer Lists" << std::endl;
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		Span sp(10);
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest Span after adding vector: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span after adding vector: " << sp.longestSpan() << std::endl;

		std::list<int> lst;
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);
		lst.push_back(60);
		lst.push_back(70);
		sp.addNumbers(lst.begin(), lst.end());
		std::cout << "Shortest Span after adding list: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span after adding list: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}