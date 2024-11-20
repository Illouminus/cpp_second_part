#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


typedef AForm* (*FormCreator)(const std::string& target);


AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}


struct FormPair {
    std::string name;
    FormCreator creator;
};

static const FormPair formPairs[] = {
    {"shrubbery creation", createShrubberyCreationForm},
    {"robotomy request", createRobotomyRequestForm},
    {"presidential pardon", createPresidentialPardonForm}
};


Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}


Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}


Intern::~Intern() {}

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
