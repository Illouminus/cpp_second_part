// Intern.cpp
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Тип определения для указателя на функцию создания формы
typedef AForm* (*FormCreator)(const std::string& target);

// Статические методы для создания конкретных форм
AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Таблица соответствий между названиями форм и функциями создания
struct FormPair {
    std::string name;
    FormCreator creator;
};

static const FormPair formPairs[] = {
    {"shrubbery creation", createShrubberyCreationForm},
    {"robotomy request", createRobotomyRequestForm},
    {"presidential pardon", createPresidentialPardonForm}
};

// Конструктор по умолчанию
Intern::Intern() {}

// Конструктор копирования
Intern::Intern(const Intern& other) {
    (void)other;
}

// Оператор присваивания
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// Деструктор
Intern::~Intern() {}

// Метод makeForm
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    for (size_t i = 0; i < sizeof(formPairs)/sizeof(FormPair); ++i) {
        if (formPairs[i].name == formName) {
            AForm* form = formPairs[i].creator(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern couldn't create " << formName << " because it does not exist." << std::endl;
    return NULL;
}
