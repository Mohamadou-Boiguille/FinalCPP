#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>

Bureaucrat *announce(std::string name, int rank)
{
    Bureaucrat *somebody = new Bureaucrat(name, rank);
    return somebody;
}

Form *createForms(std::string formName, int requiredSign, int requiredExec)
{
        Form *form = new Form(formName, requiredSign, requiredExec);
        return form;
}

void signForms(Form *form, Bureaucrat *bureaucrat)
{
    try
    {
        form->beSigned(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    std::cout << "\n==== created Bureaucrats ====" << std::endl;
    std::string initNames[5] = {"Marc", "Jeanne", "Jacques", "Wrong - Grade At 0", "Grade At 151"};
    int initGrades[5] = {4, 147, 147, 0, 151};
    int validBureaucrats[5] = {0, 0, 0, 0, 0};
    int validForms[5] = {0, 0, 0, 0, 0};
    Bureaucrat *bureaucratArray[5];
    Form *formArr[5];
    std::string strArr[5] = {"FormA", "FormB", "FormC", "FormD", "FormE"};
    int requiredSign[5] = {15, 148, 146, 0, 3};
    int requiredExec[5] = {15, 147, 3, 3, 151};
    for (int i = 0; i < 5; i++)
    {
        bureaucratArray[i] = NULL;
        formArr[i] = NULL;
        try
        {
            bureaucratArray[i] = announce(initNames[i], initGrades[i]);
            validBureaucrats[i] = 1;
        }
        catch (const std::exception &e)
        {
            validBureaucrats[i] = 0;
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "\n==== << operator ====" << std::endl;
    for (int i = 0; i < 5; i++)
        if (validBureaucrats[i] == 1)
            std::cout << *bureaucratArray[i];

    std::cout << "\n==== create Forms ====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        validForms[i] = 0;
        try
        {
            formArr[i] = createForms(strArr[i], requiredSign[i], requiredExec[i]);
            validForms[i] = 1;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "\n==== << operator for forms ====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (validForms[i] == 1)
            std::cout << *formArr[i];
    }

    std::cout << "\n==== sign Forms ====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (validForms[i] && validBureaucrats[i])
        {
            signForms(formArr[i], bureaucratArray[i]);
        }
    }

    std::cout << "\n==== delete allocated memory ====" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (validBureaucrats[i])
            delete bureaucratArray[i];
        if (validForms[i])
            delete formArr[i];
    }
    return 0;
}
