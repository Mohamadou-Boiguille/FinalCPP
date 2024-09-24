# include "../inc/Form.hpp"

Form ::Form() : name("random form"), isFormSigned(false), minExec(1), minSign(1)
{
  std::cout << "Form '" << name << "' is created ";
  std::cout << "- Sign Grade : " << minSign;
  std::cout << " - Execute grade : " << minExec;
  std::cout << std::endl;
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
    std::cout << "Form '" << name << "' is created ";
    std::cout << "- Sign Grade : " << minSign;
    std::cout << " - Execute grade : " << minExec;
    std::cout << std::endl;
  }
}

Form ::Form(const Form &other)
    : name(other.name), isFormSigned(other.isFormSigned), minExec(other.minExec),
      minSign(other.minSign)
{
  std::cout << "Form '" << name << "' is duplicated ";
  std::cout << "- Sign Grade : " << minSign;
  std::cout << " - Execute grade : " << minExec;
  std::cout << std::endl;
}

Form &Form ::operator=(const Form &other)
{
  if (this != &other)
  {
    this->isFormSigned = other.isFormSigned;
  }
  return (*this);
}

Form ::~Form()
{
}

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << form.getName() << " form - grade to sign: " << form.getMinSign() << " - grade to execute: " << form.getMinExec() << std::endl;
	return os;
}

unsigned int Form ::getMinSign()
{
  return (this->minSign);
}

unsigned int Form ::getMinExec()
{
  return (this->minExec);
}

bool Form ::getIfSigned()
{
  return (this->isFormSigned);
}

std::string Form ::getName()
{
  return (this->name);
}

void Form ::beSigned(const Bureaucrat &bcrat)
{
  if (this->isFormSigned == true)
  {
    std::cout << this->getName() << " is already signed." << std::endl;
  }
  else if (bcrat.getGrade() <= this->getMinSign())
  {
    this->isFormSigned = true;
    std::cout << bcrat.getName() << " signed ";
    std::cout << this->getName() << "." << std::endl;
  }
  else
    throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade level too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Form grade level too low.");
}