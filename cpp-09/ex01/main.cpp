
#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}

	RPN calculator;
	try
	{
		int result = calculator.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const char *msg)
	{
		std::cerr << msg << std::endl;
		return 1;
	}

	return 0;
}
