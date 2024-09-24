#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    validateExecution(executor);
    std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());
    if (!outfile)
    {
        throw std::ios_base::failure("Failed to open file.");
    }
    outfile << "    *\n   ***\n  *****\n *******\n*********\n   | |\n   | |";
    outfile << "    *\n   ***\n  *****\n *******\n*********\n   | |\n   | |";
    outfile.close();
}

