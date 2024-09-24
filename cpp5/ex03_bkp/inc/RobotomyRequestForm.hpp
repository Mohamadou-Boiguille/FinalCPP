#include "Form.hpp"

class RobotomyRequestForm : public Form
{
  public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;
    std::string getTarget() const;

  private:
	std::string target;
};
