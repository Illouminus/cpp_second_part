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
	stack.clear(); // Clear the stack before evaluating a new expression because the stack is a member variable of the class
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		// Check if the token is a number
		if (!token.empty() && std::all_of(token.begin(), token.end(), ::isdigit))
		{
			int number = std::atoi(token.c_str());
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

			// Perform the operation based on the operator
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
				throw "Error: Unknown operator";
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
