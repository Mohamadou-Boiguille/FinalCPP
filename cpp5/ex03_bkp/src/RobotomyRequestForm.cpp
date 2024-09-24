#include "../inc/RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
: Form("unknown", 145, 137), target("unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form(target, 145, 137), target(target)
{
}

// RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
//     *this = other;
// }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
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
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "BrrZzrrRzzRRR\n";
    bool fiftyFifty = rand() % 2;
    if (fiftyFifty)
        std::cout << target << " was successfully robotomized";
    else
        std::cout << target << " robotomization failed";
    std::cout << std::endl;
}
