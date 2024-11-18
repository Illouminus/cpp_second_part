#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	 : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	 : name(other.name),
		isSigned(other.isSigned),
		gradeToSign(other.gradeToSign),
		gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

// Геттеры
const std::string &AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException: Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm::FormNotSignedException: Form is not signed!";
}

const char *AForm::GradeTooLowToExecuteException::what() const throw()
{
	return "AForm::GradeTooLowToExecuteException: Grade too low to execute form!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName()
		<< " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExecute() << "]";
	return os;
}