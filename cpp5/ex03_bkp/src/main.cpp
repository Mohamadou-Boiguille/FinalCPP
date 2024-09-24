#include "../inc/Intern.hpp"
#include <ostream>

int main (void) {
    Intern one;

    Form *first;
    Form *second;
    Form *third;
    Form *fourth;

    first = one.makeForm("whatever", "whatever");
    (void)first;
    // std::cout << *first << std::endl;
    second = one.makeForm("presidential pardon", "");
    std::cout << *second << std::endl;
    third = one.makeForm("robotomy request", "robotomy_target");
    std::cout << *third << std::endl;
    fourth = one.makeForm("shrubbery creation", "shrubbery_target");
    std::cout << *fourth << std::endl;
    Bureaucrat *Marc;
    // Bureaucrat *Jeanne;
    // Bureaucrat *noName;
    // std::cout << "\n==== Bureaucrats ====" << std::endl;
    try {
        std::cout << "new Bureaucrat(\"Marc\", 4)" << std::endl;
        Marc = new Bureaucrat("Marc", 4);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    Marc->signForm(fourth);
    std::cout << *fourth << std::endl;
    // try {
    //     std::cout << "new Bureaucrat(\"Jeanne\", 146)" << std::endl;
    //     Jeanne = new Bureaucrat("Jeanne", 146);
    // } catch (std::exception &e) {
    //     std::cout << e.what() <<std::endl;
    // }
    // try {
    //     std::cout << "new Bureaucrat(\"\", 135)" << std::endl;
    //     noName = new Bureaucrat("", 135);
    // } catch (std::exception &e) {
    //     std::cout << e.what() <<std::endl;
    // }
    // Bureaucrat TooHigh("TooHigh", 151);
    // Bureaucrat TooLow("TooLow", 0);
    // TooHigh.promote();
    // TooHigh.relegate();
    // Form *formTest = new ShrubberyCreationForm("Test_target");
    // TooHigh.signForm(formTest);
    // std::cout << "<< operator give : "<< TooLow << std::endl;

    // std::cout << "\n==== Forms ====" << std::endl;
    // ShrubberyCreationForm *form;
    // try {
    //     form = new ShrubberyCreationForm("Shrub_target");
    // } catch (std::exception &e) {
    //     std::cout << e.what() <<std::endl;
    // }
    // RobotomyRequestForm *formTwo;
    // try {
    //     formTwo = new RobotomyRequestForm("Robot_target");
    // } catch (std::exception &e) {
    //     std::cout << e.what() <<std::endl;
    // }
    // PresidentialPardonForm *formThree;
    // try {
    //     formThree = new PresidentialPardonForm("Pres_target");
    // } catch (std::exception &e) {
    //     std::cout << e.what() <<std::endl;
    // }
    // std::cout << "\n==== First ====" << std::endl;
    // Jeanne->signForm(form);
    // form->execute(*Jeanne);
    // Marc->signForm(form);
    // noName->signForm(form);
    // form->execute(*Jeanne);
    // form->execute(*noName);
    // std::cout << "\n==== Second ====" << std::endl;
    // Jeanne->signForm(formTwo);
    // formTwo->execute(*Jeanne);
    // Marc->signForm(formTwo);
    // noName->signForm(formTwo);
    // formTwo->execute(*Jeanne);
    // formTwo->execute(*noName);
    // std::cout << "\n==== Third ====" << std::endl;
    // Jeanne->signForm(formThree);
    // formThree->execute(*Jeanne);
    // Marc->signForm(formThree);
    // noName->signForm(formThree);
    // formThree->execute(*Jeanne);
    // formThree->execute(*noName);
    // formThree->execute(*Marc);
    // for (int i = 0; i < 5; i++) {
    //     Marc->promote();
    //     Jeanne->relegate();
    // }
    // std::cout << "User: " << *Marc;
    // delete Marc;
    // delete Jeanne;
    // delete noName;
    // delete form;
    // delete formTwo;
    // delete formThree;
    return 0;
}
