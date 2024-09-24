#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n==== Bureaucrat Creation ====" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 140);
        Bureaucrat b2("Bob", 1);
        Bureaucrat b3("Eve", 50);

        std::cout << "\n==== ShrubberyCreationForm Test ====" << std::endl;
        ShrubberyCreationForm shrubForm("Home");
        b1.signForm(shrubForm);
        b1.executeForm(shrubForm); // Should fail execution due to grade being too low

        std::cout << "\n==== Promote Bureaucrat Alice ====" << std::endl;
        b1.promote();              // Promote to grade 139
        b1.promote();              // Promote to grade 138
        b1.executeForm(shrubForm); // Should succeed

        std::cout << "\n==== RobotomyRequestForm Test ====" << std::endl;
        RobotomyRequestForm robotForm("Robot");
        b2.signForm(robotForm);
        b3.executeForm(robotForm); // Eve should have the grade to execute

        std::cout << "\n==== PresidentialPardonForm Test ====" << std::endl;
        PresidentialPardonForm pardonForm("Marvin");
        b2.signForm(pardonForm);
        b2.executeForm(pardonForm); // Bob should execute successfully
        std::cout << "\n==== Test Complete ====\n" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n==== End ====" << std::endl;

    return 0;
}
