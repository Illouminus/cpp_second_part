#include "PmergeMe.hpp"

// ***** Constructors, destructor, operator= *****
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error: No input provided.");
	parseArguments(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
	vec = other.vec;
	deq = other.deq;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	vec = other.vec;
	deq = other.deq;
	return *this;
}
PmergeMe::~PmergeMe() {}

// ***** Member functions *****

bool PmergeMe::isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

// Parising input arguments
void PmergeMe::parseArguments(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		// Remove leading and trailing whitespaces
		arg.erase(0, arg.find_first_not_of(" \t\r\n"));
		arg.erase(arg.find_last_not_of(" \t\r\n") + 1);

		if (!isNumber(arg))
			throw std::invalid_argument("Error: Non-numeric input detected.");

		long num = std::atol(arg.c_str());
		if (num <= 0 || num > 2147483647)
			throw std::out_of_range("Error: Number out of range.");

		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}

	if (vec.empty())
		throw std::invalid_argument("Error: No valid numbers provided.");
}

// Print the original sequence
void PmergeMe::printBefore()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i != vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

// Вывод отсортированной последовательности
void PmergeMe::printAfter()
{
	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i != vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

// Algorithm for sorting merge-insert for std::vector
void PmergeMe::sortVector()
{
	std::vector<int> temp(vec.size());
	std::function<void(int, int)> mergeSort = [&](int left, int right)
	{
		if (left >= right)
			return;
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		int i = left, j = mid + 1, k = left;
		while (i <= mid && j <= right)
		{
			if (vec[i] < vec[j])
				temp[k++] = vec[i++];
			else
				temp[k++] = vec[j++];
		}
		while (i <= mid)
			temp[k++] = vec[i++];
		while (j <= right)
			temp[k++] = vec[j++];
		for (int l = left; l <= right; ++l)
			vec[l] = temp[l];
	};

	mergeSort(0, vec.size() - 1);
}

// Along with the sorting algorithm for std::deque
void PmergeMe::sortDeque()
{
	std::deque<int> temp(deq.size());

	std::function<void(int, int)> mergeSort = [&](int left, int right)
	{
		if (left >= right)
			return;
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		int i = left, j = mid + 1, k = left;
		while (i <= mid && j <= right)
		{
			if (deq[i] < deq[j])
				temp[k++] = deq[i++];
			else
				temp[k++] = deq[j++];
		}
		while (i <= mid)
			temp[k++] = deq[i++];
		while (j <= right)
			temp[k++] = deq[j++];
		for (int l = left; l <= right; ++l)
			deq[l] = temp[l];
	};

	mergeSort(0, deq.size() - 1);
}

void PmergeMe::execute()
{
	printBefore();

	// Sorting and measuring time for std::vector
	std::clock_t startVec = std::clock();
	sortVector();
	std::clock_t endVec = std::clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6; // microseconds

	// Sorting and measuring time for std::deque
	std::clock_t startDeq = std::clock();
	sortDeque();
	std::clock_t endDeq = std::clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6; // microseconds

	printAfter();

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
