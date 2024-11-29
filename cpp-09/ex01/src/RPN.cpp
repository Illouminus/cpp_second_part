#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <cstring>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return *this;
}

int RPN::evaluate(const std::string &expression) throw(const char *)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		// Check if the token is a number
		if (token.length() == 1 && std::isdigit(token[0]))
		{
			int number = token[0] - '0';
			stack.push_back(number);
		}
		// Check if the token is an operator
		else if (token.length() == 1 && std::strchr("+-*/", token[0]))
		{
			if (stack.size() < 2)
			{
				throw "Error: Not enough operands";
			}
			// Pop the last two elements from the stack
			int b = stack.back();
			stack.pop_back();
			int a = stack.back();
			stack.pop_back();
			int result;

			// Perform the operation
			switch (token[0])
			{
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				if (b == 0)
				{
					throw "Error: Division by zero";
				}
				result = a / b;
				break;
			default:
				throw "Error: Unknow operator";
			}
			stack.push_back(result);
		}
		else
		{
			throw "Error: Invalid token";
		}
	}

	if (stack.size() != 1)
	{
		throw "Error: Too many operands";
	}

	return stack.back();
}
