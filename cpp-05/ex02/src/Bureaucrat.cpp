#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName()
					 << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute " << form.getName()
					 << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
