// main.cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Form and Bureaucrat Class Comprehensive Test ===\n\n";

	Bureaucrat alice("Alice", 50);
	Bureaucrat bob("Bob", 1);
	Bureaucrat charlie("Charlie", 150);

	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << charlie << std::endl;

	std::cout << "\n";

	try
	{
		Form taxForm("Tax Form", 25, 5);
		Form leaveForm("Leave Form", 100, 50);
		Form topSecretForm("Top Secret Form", 0, 10);

		std::cout << taxForm << std::endl;
		std::cout << leaveForm << std::endl;
		std::cout << topSecretForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught while creating forms: " << e.what() << std::endl;
	}

	std::cout << "\n";

	Form taxForm("Tax Form", 25, 5);
	Form leaveForm("Leave Form", 100, 50);

	std::cout << taxForm << std::endl;
	std::cout << leaveForm << std::endl;

	std::cout << "\n";

	alice.signForm(taxForm);
	bob.signForm(taxForm);
	charlie.signForm(leaveForm);

	std::cout << "\n";

	std::cout << taxForm << std::endl;
	std::cout << leaveForm << std::endl;

	std::cout << "\n=== End of Test ===\n";
	return 0;
}