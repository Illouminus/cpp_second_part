#pragma once
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	// Конструкторы и деструктор
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	// Геттеры
	const std::string &getName() const;
	int getGrade() const;

	// Методы для изменения рейтинга
	void incrementGrade(); // Улучшение (уменьшение числа)
	void decrementGrade(); // Ухудшение (увеличение числа)

	// Исключения
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);