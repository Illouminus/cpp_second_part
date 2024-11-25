// main.cpp
#include <iostream>
#include <string>
#include "Iter.hpp"

template <typename T>
void printElement(const T &element)
{
	std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element)
{
	++element;
}

void appendExclamation(std::string &s)
{
	s += "!";
}

void toUpperCase(char &c)
{
	c = toupper(c);
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original intArray: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intLength, incrementElement<int>);

	std::cout << "intArray after increment: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	std::string strArray[] = {"Hello", "World", "Iter", "Function"};
	size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Original strArray: ";
	iter(strArray, strLength, printElement<std::string>);
	std::cout << std::endl;

	iter(strArray, strLength, appendExclamation);

	std::cout << "strArray after appending '!': ";
	iter(strArray, strLength, printElement<std::string>);
	std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charLength = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original charArray: ";
	iter(charArray, charLength, printElement<char>);
	std::cout << std::endl;

	iter(charArray, charLength, toUpperCase);

	std::cout << "charArray after toupper: ";
	iter(charArray, charLength, printElement<char>);
	std::cout << std::endl;

	return 0;
}