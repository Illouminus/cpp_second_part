#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Bureaucrat Class Comprehensive Test ===\n\n";

	try
	{
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 75);
		Bureaucrat b3("Charlie", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught during creation of valid Bureaucrat: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b4("Dave", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught while creating Dave: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b5("Eve", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught while creating Eve: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b6("Frank", 2);
		std::cout << b6 << std::endl;

		b6.incrementGrade();
		std::cout << "After increment: " << b6 << std::endl;

		b6.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught during increment: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b7("Grace", 149);
		std::cout << b7 << std::endl;

		b7.decrementGrade();
		std::cout << "After decrement: " << b7 << std::endl;

		b7.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught during decrement: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b8("Heidi", 100);
		Bureaucrat b9 = b8;
		std::cout << "Original: " << b8 << std::endl;
		std::cout << "Copy: " << b9 << std::endl;

		Bureaucrat b10("Ivan", 50);
		std::cout << "Before assignment, b10: " << b10 << std::endl;
		b10 = b8;
		std::cout << "After assignment, b10: " << b10 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught during copy/assignment: " << e.what() << std::endl;
	}

	std::cout << "\n=== End of Test ===\n";
	return 0;
}