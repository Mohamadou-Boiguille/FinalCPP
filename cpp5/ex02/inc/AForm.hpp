#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    AForm(std::string name, unsigned int minSign, unsigned int minExec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    unsigned int getMinSign() const;
    unsigned int getMinExec() const;
    bool getIfSigned() const;
    void beSigned(const Bureaucrat &bcrat);

    virtual void execute(Bureaucrat const &executor) const = 0;

protected:
    void validateExecution(Bureaucrat const &executor) const;

private:
    const std::string name;
    bool isFormSigned;
    const unsigned int minSign;
    const unsigned int minExec;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
