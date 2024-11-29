#pragma once

#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <iostream>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deq;

	// Вспомогательные методы
	bool isNumber(const std::string &str);
	void parseArguments(int argc, char **argv);
	void printBefore();
	void printAfter();

	// Алгоритм сортировки merge-insert для std::vector
	void sortVector();

	// Алгоритм сортировки merge-insert для std::deque
	void sortDeque();

public:
	// Конструктор
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	// Основной метод для выполнения сортировки и вывода результатов
	void execute();
};
