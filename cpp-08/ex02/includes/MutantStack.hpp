#pragma once

#include <stack>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	MutantStack() : std::stack<T, Container>() {}

	MutantStack(const MutantStack<T, Container> &other) : std::stack<T, Container>(other) {}

	MutantStack &operator=(const MutantStack<T, Container> &other)
	{
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	// Method begin() returns an iterator to the first element
	iterator begin()
	{
		return this->c.begin();
	}

	// Method end() returns an iterator to the element following the last
	iterator end()
	{
		return this->c.end();
	}

	// Method cbegin() returns a constant iterator to the first element
	const_iterator begin() const
	{
		return this->c.begin();
	}

	// Method cend() returns a constant iterator to the element following the last
	const_iterator end() const
	{
		return this->c.end();
	}

	// Method rbegin() returns a reverse iterator to the last element
	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}

	// Method rend() returns a reverse iterator to the element preceding the first
	reverse_iterator rend()
	{
		return this->c.rend();
	}

	// Method crbegin() returns a constant reverse iterator to the last element
	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}

	// Method crend() returns a constant reverse iterator to the element preceding the first
	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}
};
