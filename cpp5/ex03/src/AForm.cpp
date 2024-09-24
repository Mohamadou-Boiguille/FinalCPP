#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, unsigned int minSign, unsigned int minExec)
    : name(name), isFormSigned(false), minSign(minSign), minExec(minExec)
{
    if (minSign < 1 || minExec < 1)
        throw GradeTooHighException();
    if (minSign > 150 || minExec > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << name << " created. Sign grade: " << minSign
              << ", Execute grade: " << minExec << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), isFormSigned(other.isFormSigned),
      minSign(other.minSign), minExec(other.minExec)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isFormSigned = other.isFormSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm " << this->name << " is destroyed." << std::endl;
}

std::string AForm::getName() const
{
    return this->name;
}

unsigned int AForm::getMinSign() const
{
    return this->minSign;
}

unsigned int AForm::getMinExec() const
{
    return this->minExec;
}

bool AForm::getIfSigned() const
{
    return this->isFormSigned;
}

void AForm::beSigned(const Bureaucrat &bcrat)
{
    if (bcrat.getGrade() > this->getMinSign())
        throw GradeTooLowException();
    if (this->isFormSigned)
        throw FormAlreadySignedException();
    this->isFormSigned = true;
    std::cout << bcrat.getName() << " signed form " << this->getName() << std::endl;
}

void AForm::validateExecution(Bureaucrat const &executor) const
{
    if (!this->getIfSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getMinExec())
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed, cannot execute.";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
    return "Form is already signed.";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName() << ", Sign grade: " << form.getMinSign()
       << ", Execute grade: " << form.getMinExec() 
       << ", Signed: " << (form.getIfSigned() ? "Yes" : "No");
    return os;
}
