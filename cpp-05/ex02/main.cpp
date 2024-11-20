#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Form and Bureaucrat Class Comprehensive Test ===\n\n";

	try
	{
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 1);				
		Bureaucrat charlie("Charlie", 150);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;

		std::cout << "\n";

		ShrubberyCreationForm shrubForm("home");
		RobotomyRequestForm robotForm("Bender");
		PresidentialPardonForm pardonForm("Ford Prefect");

		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << "\n";

		alice.signForm(shrubForm);	 
		alice.signForm(robotForm);	 
		alice.signForm(pardonForm);

		std::cout << "\n";

		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << "\n";

		charlie.executeForm(shrubForm); // Cannot execute
		alice.executeForm(shrubForm);	  // Can execute
		bob.executeForm(robotForm);	  // Can execute
		bob.executeForm(pardonForm);	  // Not signed yet cannot execute
		bob.executeForm(pardonForm);	  // Try to execute not signed form
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	std::cout << "\n=== End of Test ===\n";
	return 0;
}