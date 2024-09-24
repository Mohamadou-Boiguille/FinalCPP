#include "../inc/Array.hpp"
#include <iostream>

int main(void)
{
	int x = 5;
	Array<int, 8> moh;
	for (int i = 0; i < 8; i++)
	{
		try
		{
			std::cout << moh[i] << " ";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	try
	{
		std::cout << std::endl;
		std::cout << "At index " << x << " -> " << moh[x] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	x *= 2;
	try
	{
		std::cout << std::endl;
		std::cout << "At index " << x << " -> " << moh[x] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
