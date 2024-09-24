#include "../inc/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat() : name("Anonymous"), grade(150)
{
	std::cout << "Anonymous bureaucrat created (grade 150)" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
	: name(name), grade(grade)
{
	if (grade < 1)
	{
		std::cout << name << "'s creation error: ";
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		std::cout << name << "'s creation error: ";
		throw GradeTooLowException();
	}
	std::cout << this->getName() << " is a new bureaucrat created (grade ";
	std::cout << this->getGrade() << ")." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.getName()), grade(other.getGrade())
{
	std::cout << this->getName() << " is a new bureaucrat duplicated (grade ";
	std::cout << this->getGrade() << ")." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.getGrade();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat)
{
	os << bcrat.getName() << ", bureaucrat grade " << bcrat.getGrade() << std::endl;
	return os;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " is erased (grade ";
	std::cout << this->getGrade() << ")." << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Invalid grade (too high).");
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Invalid grade (too low).");
}

void Bureaucrat::promote()
{
	if (this->grade <= 1) {
		std::cout << "promote error: ";
		throw GradeTooHighException();
	}
	this->grade -= 1;
	std::cout << name << " is promoted from grade " << this->grade + 1;
	std::cout << " to " << getGrade() << std::endl;
}

void Bureaucrat::relegate()
{ 
	if (this->grade >= 150) {
		std::cout << "relegate error: ";
	throw GradeTooLowException();}
	this->grade += 1;
	std::cout << name << " is relegated from grade " << this->grade - 1;
	std::cout << " to " << getGrade() << std::endl;
}

void Bureaucrat::signForm(Form &form) const
{
	try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " sign " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
    }
}

