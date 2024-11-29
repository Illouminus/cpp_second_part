// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	bool parseInput(int argc, char *argv[]);
	void printBefore() const;
	void printAfter() const;
	void sortContainers();
	void printTimes() const;

private:
	std::vector<int> vec;
	std::deque<int> deq;

	// Timing variables in microseconds
	double vecTime;
	double deqTime;

	// Helper functions for sorting
	void mergeInsertSortVector(std::vector<int> &data);
	void mergeInsertSortDeque(std::deque<int> &data);

	// Timer function
	double getTime() const;
};

#endif // PMERGEME_HPP
