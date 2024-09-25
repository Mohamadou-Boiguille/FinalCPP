#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2 || sizeof(argv[1]) == 0)
	{
		std::cout << "Invalid input - Usage: ./Scalar + one argument" << std::endl;
		return 1;
	}
    std::string str(argv[1]);
	ScalarConverter::convert(str);
	return 0;
}
