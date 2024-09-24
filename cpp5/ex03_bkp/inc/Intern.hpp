#ifndef INTERN_HPP
# define INTERN_HPP

# include "../inc/Form.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

class Intern
{
  public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	Form *makeForm(std::string fName, std::string target);

  private:
};
#endif // !INTERN_HPP
