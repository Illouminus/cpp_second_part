#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	 : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	 : AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowToExecuteException();

	std::cout << "Bzzzz... Drilling noises..." << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}