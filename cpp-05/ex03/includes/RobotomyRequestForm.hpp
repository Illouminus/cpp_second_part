#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	virtual void execute(const Bureaucrat &executor) const;
};
