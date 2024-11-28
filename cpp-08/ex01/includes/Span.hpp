#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>
#include <cstddef>

class SpanFullException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Span is already full. Cannot add more numbers.";
	}
};

class NotEnoughNumbersException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Not enough numbers to find a span.";
	}
};

class Span
{
private:
	std::vector<int> numbers;
	unsigned int maxSize;

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + numbers.size() > maxSize)
			throw SpanFullException();
		numbers.insert(numbers.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;
};
