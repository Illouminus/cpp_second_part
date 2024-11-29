#pragma once

#include <string>
#include <vector>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	int evaluate(const std::string &expression) throw(const char *);

private:
	std::vector<int> stack;
};
