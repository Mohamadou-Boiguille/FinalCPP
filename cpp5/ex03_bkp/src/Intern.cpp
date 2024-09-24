#include "../inc/Intern.hpp"
#include <sstream>
#include <string>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
  *this = other;
}

Intern& Intern::operator=(const Intern& other) {
  if (this != &other) {
  }
  return *this;
}

Intern::~Intern() {
}

Form *Intern ::makeForm(std::string fName, std::string target)
{
    Form *form = NULL;
    if (fName == "shrubbery creation")
        form = new ShrubberyCreationForm(target.empty() ? "Unknown" : target);
    else if (fName == "robotomy request")
        form = new RobotomyRequestForm(target.empty() ? "Unknown" : target);
    else if (fName == "presidential pardon")
        form = new PresidentialPardonForm(target.empty() ? "Unknown" : target);
    else
    {
        std::cout << RED_COLOR << fName << "' form doesn't exists.";
        std::cout << RESET_COLOR << std::endl;
        return NULL;
    }
    std::cout << GREEN_COLOR;
    std::cout << "Intern creates " << (target.empty() ? "Unknown" : target);
    std::cout << std::endl << RESET_COLOR;
    return form;
}

