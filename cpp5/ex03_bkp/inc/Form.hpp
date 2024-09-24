#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;
class Form
{
  public:
	Form();
	Form(std::string name, unsigned int minSign, unsigned int minExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	unsigned int getMinSign() const;
	unsigned int getMinExec() const;
	bool getIfSigned() const;
	std::string getName() const;
	void beSigned(Bureaucrat *bcrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
    bool checkGradeAndSignature(Bureaucrat const & executor) const;
    void execFailLog(std::string bName, std::string fName, std::exception &e) const;
    void display(std::ostream &os) const;
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("grade is too low");
		}
	};
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("grade is too high");
		}
	};
	class AlreadySigned : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("already signed");
		}
	};
	class NotSigned : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("not signed");
		}
	};

  private:
    std::string target;
	const std::string name;
	bool isFormSigned;
	unsigned int minExec;
	unsigned int minSign;
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif // !FORM_HPP
