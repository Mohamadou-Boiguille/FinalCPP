#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#define ALL 0
#define PROMOTE 1
#define RELEGATE 2

Bureaucrat::Bureaucrat()
{
}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
	: name(name.empty() ? "John Doe" : name), grade(grade)
{
	try
	{
		checkGrade(ALL);
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR;
		std::cout << getName() << " is invalid because " << e.what() << ".";
		std::cout << std::endl
					<< RESET_COLOR;
		this->is_valid = false;
		return ;
	}
	std::cout << GREY_COLOR << "Bureaucrat creation log : ";
	std::cout << this->name << " (Grade ";
	std::cout << this->grade << ") is created." << RESET_COLOR;
	std::cout << std::endl;
	this->is_valid = true;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
		this->name = other.name;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// Destructor implementation
}

std::string Bureaucrat::getName() const
{
	if (this->is_valid == false)
		return ("Invalid Bureaucrat");
	return (this->name);
}

unsigned int Bureaucrat::getGrade() const
{
	if (this->is_valid == false)
		return (-1);
	return (this->grade);
}

bool Bureaucrat::bcratIsValid() const
{
	if (this->is_valid)
		return (true);
	else
	{
		throw InvalidBureaucrat();
		return (false);
	}
}

void Bureaucrat::promote()
{
	try
	{
		bcratIsValid();
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR << "Can't promote. " << e.what() << std::endl;
		std::cout << RESET_COLOR;
		return ;
	}
	try
	{
		checkGrade(PROMOTE);
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR;
		std::cout << this->getName() << " is level ";
		std::cout << this->getGrade() << " , can't promote.";
		std::cout << std::endl
					<< RESET_COLOR;
		return ;
	}
	this->grade -= 1;
	log("promoted", this->grade + 1);
}

void Bureaucrat::relegate()
{
	try
	{
		bcratIsValid();
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR << "Can't relegate. " << e.what() << std::endl;
		std::cout << RESET_COLOR;
		return ;
	}
	try
	{
		checkGrade(RELEGATE);
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR;
		std::cout << this->getName() << " is level ";
		std::cout << this->getGrade() << " , can't relegate.";
		std::cout << std::endl
					<< RESET_COLOR;
		return ;
	}
	this->grade += 1;
	log("relegate", this->grade - 1);
}

void Bureaucrat::signForm(Form *toSign)
{
	try
	{
		bcratIsValid();
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR << "Can't sign. " << e.what() << std::endl;
		std::cout << RESET_COLOR;
		return ;
	}
	try
	{
		toSign->beSigned(this);
	}
	catch (std::exception &e)
	{
		std::cout << RED_COLOR;
		std::cout << this->getName() << " couldn't sign " << toSign->getName();
		std::cout << " because " << e.what() << "." << std::endl;
		std::cout << RESET_COLOR;
		return ;
	}
	std::cout << GREEN_COLOR;
	std::cout << this->getName() << " signed " << toSign->getName() << std::endl;
	std::cout << RESET_COLOR;
}

// PRIVATE FUNCTIONS

void Bureaucrat::checkGrade(int action)
{
	if (this->grade <= 1 && (action == PROMOTE || action == ALL))
		throw GradeTooHighException();
	if (this->grade >= 150 && (action == RELEGATE || action == ALL))
		throw GradeTooLowException();
}

void Bureaucrat::log(std::string action, unsigned int oldGrade)
{
	std::cout << GREY_COLOR << "Bureaucrat log : ";
	std::cout << name << " is " << action;
	std::cout << " from grade " << oldGrade;
	std::cout << " to " << getGrade() << std::endl;
	std::cout << RESET_COLOR;
}

void Bureaucrat::gradeError(std::string action)
{
	std::cout << this->name << " is at grade " << getGrade();
	std::cout << " and cannot be " << action << "." << std::endl;
}

// OTHER

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat)
{
	try
	{
		bcrat.bcratIsValid();
	}
	catch (std::exception &e)
	{
		os << RED_COLOR;
		os << e.what() << std::endl;
		os << RESET_COLOR;
		return (os);
	}
	os << bcrat.getName() << ",	bureaucrat grade ";
	os << bcrat.getGrade() << std::endl;
	return (os);
}
