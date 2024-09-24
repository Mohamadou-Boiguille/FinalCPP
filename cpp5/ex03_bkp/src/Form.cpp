#include "../inc/Form.hpp"

Form ::Form()
{
}

Form ::Form(std::string name, unsigned int minSign, unsigned int minExec)
	: name(name), isFormSigned(false), minExec(minExec), minSign(minSign)
{
    if (minSign == 0 || minExec == 0)
		throw GradeTooHighException();
    else if (minSign > 150 || minExec > 150)
		throw GradeTooLowException();
    else
    {
        std::cout << GREY_COLOR;
        std::cout << "Form creation log : " << name;
        std::cout << " - Sign Grade : " << minSign;
        std::cout << " - Execute grade : " << minExec;
        std::cout << std::endl;
        std::cout << RESET_COLOR;
    }
}

Form ::Form(const Form &other)
{
    *this = other;
}
Form &Form ::operator=(const Form &other)
{
    (void)other;
	return (*this);
}

Form ::~Form()
{
}

unsigned int Form ::getMinSign() const
{
	return (this->minSign);
}
unsigned int Form ::getMinExec() const
{
	return (this->minExec);
}
bool Form ::getIfSigned() const
{
	return (this->isFormSigned);
}
std::string Form ::getName() const
{
	return (this->name);
}
void Form ::beSigned(Bureaucrat *bcrat)
{
	if (bcrat->getGrade() > this->getMinSign())
		throw GradeTooLowException();
    if (this->isFormSigned == true)
        throw AlreadySigned();
    std::cout << GREY_COLOR << "beSigned() log : ";
    std::cout << bcrat->getName() << " successfully signed ";
    std::cout << this->getName() << "." << RESET_COLOR << std::endl;
	this->isFormSigned = true;
}

void Form ::display(std::ostream &os) const
{
    os << this->getName() << " Form (";
    if (this->getIfSigned() == false)
        os << "not ";
    os << "signed).";
}

bool Form::checkGradeAndSignature(Bureaucrat const & executor) const
{
    if (getIfSigned() == false)
    {
        throw NotSigned();
        return false;
    }
    if (executor.getGrade() > getMinExec())
    {
        throw GradeTooLowException();
        return false;
    }
    return true;
}

void Form ::execute(Bureaucrat const & executor) const
{
    try {
        checkGradeAndSignature(executor);
    } catch (std::exception &e) {
        std::cout << "error : " << e.what();
    }
}

void Form ::execFailLog(std::string bName, std::string fName, std::exception &e) const
{
    std::cout << RED_COLOR;
    std::cout << bName << " can't execute " << fName;
    std::cout << " (" << e.what() << ").";
    std::cout << std::endl << RESET_COLOR;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    form.display(os);
	return (os);
}
