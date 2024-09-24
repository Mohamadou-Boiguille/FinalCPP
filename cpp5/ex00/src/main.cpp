#include "../inc/Bureaucrat.hpp"

int main(void)
{
    try
    {
        // Bureaucrat pal("Jean", 400);

        Bureaucrat dude("Marc", 4);

        std::cout << "=== << operator test ===" << std::endl;
        std::cout << dude;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "=== promote " << i << " ===" << std::endl;
            try
            {
                dude.promote();
            }
            catch (std::exception &e)
            {
                std::cout << "---> ERROR : " << e.what() << "\n";
            }
        }

        Bureaucrat pow("Jeanne", 147);

        std::cout << "=== << operator test ===" << std::endl;
        std::cout << pow;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "=== relegate " << i << " ===" << std::endl;
            try
            {
                pow.relegate();
            }
            catch (std::exception &e)
            {
                std::cout << "---> ERROR : " << e.what() << "\n";
            }
        }

        Bureaucrat buddy(pow);
        std::cout << "=== << operator test ===" << std::endl;
        std::cout << buddy;
        std::cout << "=== relegate ===" << std::endl;
        try
        {
            buddy.relegate();
        }
        catch (std::exception &e)
        {
            std::cout << "---> ERROR : " << e.what() << "\n";
        }
        std::cout << "=== promote ===" << std::endl;
        try
        {
            buddy.promote();
        }
        catch (std::exception &e)
        {
            std::cout << "---> ERROR : " << e.what() << "\n";
        }

    }
    catch (std::exception &e)
    {
        std::cout << "---> ERROR : " << e.what() << "\n";
    }
    return 0;
}
