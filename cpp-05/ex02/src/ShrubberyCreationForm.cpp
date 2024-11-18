#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	 : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	 : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowToExecuteException();

	std::ofstream ofs((target + "_shrubbery").c_str());
	if (!ofs)
	{
		std::cerr << "Failed to create file: " << target << "_shrubbery" << std::endl;
		return;
	}

	ofs << "       _-_\n"
			 "    /~~   ~~\\\n"
			 " /~~         ~~\\\n"
			 "{               }\n"
			 " \\  _-     -_  /\n"
			 "   ~  \\\\ //  ~\n"
			 "_- -   | | _- _\n"
			 "  _ -  | |   -_\n"
			 "      // \\\\\n";

	ofs.close();
}