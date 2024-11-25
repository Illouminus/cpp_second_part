#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	Base *obj = Identifier::generate();

	std::cout << "Identifying by pointer: ";
	Identifier::identify(obj);

	std::cout << "Identifying by reference: ";
	try
	{
		Identifier::identify(*obj);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error during identification: " << e.what() << std::endl;
	}

	delete obj;

	return 0;
}