#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Intern Class Comprehensive Test ===\n\n";

    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* invalidForm;


    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    scf = someRandomIntern.makeForm("shrubbery creation", "home");

    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

    invalidForm = someRandomIntern.makeForm("invalid form", "Target");

    std::cout << "\n";


    if (rrf) {
        std::cout << *rrf << std::endl;
    }
    if (scf) {
        std::cout << *scf << std::endl;
    }
    if (ppf) {
        std::cout << *ppf << std::endl;
    }
    if (invalidForm) {
        std::cout << *invalidForm << std::endl;
    }

    std::cout << "\n";


    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);

    if (rrf) {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
    }

    if (scf) {
        alice.signForm(*scf); // Alice can't sign ShrubberyCreationForm
        bob.executeForm(*scf);
    }

    if (ppf) {
        bob.signForm(*ppf);
        bob.executeForm(*ppf);
    }

    delete rrf;
    delete scf;
    delete ppf;
    delete invalidForm;

    std::cout << "\n=== End of Intern Class Comprehensive Test ===\n";
    return 0;
}
