#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
  public:
  	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	Form();
	Form(std::string name, unsigned int minSign, unsigned int minExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	unsigned int getMinSign();
	unsigned int getMinExec();
	bool getIfSigned();
	std::string getName();
	void beSigned(const Bureaucrat &bcrat);

  private:
	const std::string name;
	bool isFormSigned;
	const unsigned int minExec;
	const unsigned int minSign;
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif // !FORM_HPP