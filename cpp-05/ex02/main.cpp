// main.cpp
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
		// Создание бюрократов
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 1);				// Самый высокий уровень
		Bureaucrat charlie("Charlie", 150); // Самый низкий уровень

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;

		std::cout << "\n";

		// Создание форм
		ShrubberyCreationForm shrubForm("home");
		RobotomyRequestForm robotForm("Bender");
		PresidentialPardonForm pardonForm("Ford Prefect");

		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << "\n";

		// Подписание форм
		alice.signForm(shrubForm);	 // Должен подписать успешно (grade 50 <= 145)
		alice.signForm(robotForm);	 // Должен подписать успешно (grade 50 <= 72)
		alice.signForm(pardonForm); // Не должен подписать (grade 50 < 25)

		std::cout << "\n";

		// Вывод статуса форм
		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << "\n";

		// Выполнение форм
		charlie.executeForm(shrubForm); // Не сможет выполнить (grade 150 > 137)
		alice.executeForm(shrubForm);	  // Смогет выполнить
		bob.executeForm(robotForm);	  // Смогет выполнить
		bob.executeForm(pardonForm);	  // Не подписана, не сможет выполнить
		bob.executeForm(pardonForm);	  // Попытка выполнить не подписанную форму
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	std::cout << "\n=== End of Test ===\n";
	return 0;
}