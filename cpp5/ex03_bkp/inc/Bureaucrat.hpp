#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

#define RESET_COLOR "\033[0m"
#define BLACK_COLOR "\033[30m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"
#define MAGENTA_COLOR "\033[35m"
#define CYAN_COLOR "\033[36m"
#define WHITE_COLOR "\033[37m"
#define GREY_COLOR "\033[90m"

class	Form;
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
    bool bcratIsValid() const;
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
            return "grade too low";
		}
	};
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
            return "grade too high";
		};
	};
	class InvalidBureaucrat : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
            return "Bureaucrat is invalid.";
		};
	};

	void signForm(Form *toSign);

  private:
    void checkGrade(int action);
	void log(std::string action, unsigned int oldGrade);
	void gradeError(std::string action);

	std::string name;
	unsigned int grade;
    bool is_valid;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat);

#endif // !BUREAUCRAT_HPP
