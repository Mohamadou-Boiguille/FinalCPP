#include "Form.hpp"

class PresidentialPardonForm : public Form
{
  public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();
	void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;

  private:
	std::string target;
};
