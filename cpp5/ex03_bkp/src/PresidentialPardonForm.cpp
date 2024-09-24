#include "../inc/PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm()
: Form("unknown", 25, 5), target("unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form(target, 25, 5), target(target)
{
}

// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
//     *this = other;
// }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  if (this != &other) {
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
    try
    {
        checkGradeAndSignature(executor);
    }
    catch (std::exception &e)
    {
        return execFailLog(executor.getName(), getName(), e);
    }
    std::cout << GREEN_COLOR;
    std::cout << executor.getName() << " executed " << this->getName();
    std::cout << "." << RESET_COLOR << std::endl;
    std::cout << "I forgive " << this->getTarget();
    std::cout << ".\nSincerely, Zaphod Beeblebrox." << std::endl;
}

