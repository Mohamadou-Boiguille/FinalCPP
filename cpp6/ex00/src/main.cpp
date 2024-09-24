#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <string>

int main (void) {

    std::string input;
	do {
        std::cout << "ENTER A NUMBER : ";
		std::getline(std::cin, input);
		if (input.empty())
			continue;
		if (input == "exit")
			break;
		//check for eof
		{
			ScalarConverter conversion(static_cast<std::string>(input));
		}
		std::cout << std::endl;
    } while (1);
    return 0;
}
