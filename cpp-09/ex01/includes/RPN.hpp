// RPN.hpp
#pragma once

#include <string>
#include <list>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	int evaluate(const std::string &expression) throw(const char *);

private:
	std::list<int> stack;
};
