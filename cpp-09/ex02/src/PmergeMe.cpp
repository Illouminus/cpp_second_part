#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

PmergeMe::PmergeMe() : vecTime(0.0), deqTime(0.0) {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq), vecTime(other.vecTime), deqTime(other.deqTime) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
		vecTime = other.vecTime;
		deqTime = other.deqTime;
	}
	return *this;
}

// Parsing input
bool PmergeMe::parseInput(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided." << std::endl;
		return false;
	}

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		// Check if str are not empty
		if (arg.empty())
		{
			std::cerr << "Error: Empty argument." << std::endl;
			return false;
		}
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error: Invalid character '" << arg[j] << "' in argument." << std::endl;
				return false;
			}
		}
		// Convert str to int
		int number;
		std::istringstream iss(arg);
		iss >> number;
		if (number < 0)
		{
			std::cerr << "Error: Negative number '" << number << "' is not allowed." << std::endl;
			return false;
		}
		vec.push_back(number);
		deq.push_back(number);
	}

	return true;
}

// Funtion to print the vector before sorting
void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

// Function to print the sorted vector
void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

// Function to get the current time in microseconds
double PmergeMe::getTime() const
{
	return static_cast<double>(clock()) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMe::sortContainers()
{
	// Sort the containers - vector and deque
	double startVec = getTime();
	mergeInsertSortVector(vec);
	double endVec = getTime();
	vecTime = endVec - startVec;

	double startDeq = getTime();
	mergeInsertSortDeque(deq);
	double endDeq = getTime();
	deqTime = endDeq - startDeq;
}

// Vector sorting function
void PmergeMe::mergeInsertSortVector(std::vector<int> &data)
{
	if (data.size() <= 1)
		return;

	// Step 1: Split into pairs and sort pairs
	std::vector<std::pair<int, int> > pairs;
	size_t i = 0;
	while (i + 1 < data.size())
	{
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
		else
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		i += 2;
	}

	// If odd number of elements, last element remains separate
	bool hasOdd = false;
	int lastElement = 0;
	if (i < data.size())
	{
		hasOdd = true;
		lastElement = data[i];
	}

	// Step 2: Extract minimum elements from pairs
	std::vector<int> minElements;
	std::vector<int> remainingElements;
	for (size_t j = 0; j < pairs.size(); j++)
	{
		minElements.push_back(pairs[j].first);
		remainingElements.push_back(pairs[j].second);
	}
	if (hasOdd)
	{
		minElements.push_back(lastElement);
	}

	// Step 3: Recursively sort the list of minimum elements
	mergeInsertSortVector(minElements);

	// Step 4: Insert remaining elements
	for (size_t j = 0; j < remainingElements.size(); j++)
	{
		int element = remainingElements[j];
		// Use std::lower_bound to find the insertion position
		std::vector<int>::iterator it = std::lower_bound(minElements.begin(), minElements.end(), element);
		minElements.insert(it, element);
	}

	// Step 5: Update the original list
	data = minElements;
}

// Deque sorting function
void PmergeMe::mergeInsertSortDeque(std::deque<int> &data)
{
	if (data.size() <= 1)
		return;

	// Step 1: Split into pairs and sort pairs
	std::deque<std::pair<int, int> > pairs;
	size_t i = 0;
	while (i + 1 < data.size())
	{
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
		else
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		i += 2;
	}

	// If odd number of elements, last element remains separate
	bool hasOdd = false;
	int lastElement = 0;
	if (i < data.size())
	{
		hasOdd = true;
		lastElement = data[i];
	}

	// Step 2: Extract minimum elements from pairs
	std::deque<int> minElements;
	std::deque<int> remainingElements;
	for (size_t j = 0; j < pairs.size(); j++)
	{
		minElements.push_back(pairs[j].first);
		remainingElements.push_back(pairs[j].second);
	}
	if (hasOdd)
	{
		minElements.push_back(lastElement);
	}

	// Step 3: Recursively sort the list of minimum elements
	mergeInsertSortDeque(minElements);

	// Step 4: Insert remaining elements
	for (size_t j = 0; j < remainingElements.size(); j++)
	{
		int element = remainingElements[j];
		// Use std::lower_bound to find the insertion position
		std::deque<int>::iterator it = std::lower_bound(minElements.begin(), minElements.end(), element);
		minElements.insert(it, element);
	}

	// Step 5: Update the original list
	data = minElements;
}

void PmergeMe::printTimes() const
{
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : ";
	std::cout << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}
