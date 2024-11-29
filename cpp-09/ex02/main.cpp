#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe sorter;

	// Parsing input
	if (!sorter.parseInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	// Print the vector before sorting
	sorter.printBefore();

	// Sort the containers
	sorter.sortContainers();

	// Print the vector after sorting
	sorter.printAfter();

	// Print the time taken to sort the containers
	sorter.printTimes();

	return 0;
}
