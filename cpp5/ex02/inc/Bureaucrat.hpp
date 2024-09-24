#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string getName() const;
    unsigned int getGrade() const;
    void promote();
    void relegate();
	void signForm(AForm &form) const;
	void executeForm(AForm &form) const;
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

private:
    const std::string name;
    unsigned int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat);

#endif
