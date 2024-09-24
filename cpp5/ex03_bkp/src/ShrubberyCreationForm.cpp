#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("unknown", 145, 137), target("unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form(target, 145, 137), target(target)
{
}

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
//     *this = other;
// }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  if (this != &other) {
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
        file << "    *\n   ***\n  *****\n *******\n*********\n   | |\n   | |";
        file << "    *\n   ***\n  *****\n *******\n*********\n   | |\n   | |";
        file.close();
        std::cout << GREY_COLOR;
        std::cout << filename << " file was created by " << executor.getName();
    }
    else
    {
        std::cout << RED_COLOR;
        std::cout << filename << " creation failed.";
    }
    std::cout << RESET_COLOR << std::endl;
}
