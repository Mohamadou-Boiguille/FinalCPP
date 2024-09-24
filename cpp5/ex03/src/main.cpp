#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf)
    {
        Bureaucrat b1("Alice", 1);
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
        delete rrf;
    }

    return 0;
}
