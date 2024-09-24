#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;

  private:
	std::string target;
};
