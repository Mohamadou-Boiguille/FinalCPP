#include "../inc/Array.hpp"
#include <iostream>

int main(void)
{
	int x = 5;
	Array<int, 8> moh;
	for (int i = 0; i < 8; i++)
		std::cout << moh[i] << " ";
	try
	{
		std::cout << std::endl;
		std::cout << "At index " << x << " -> " << moh[x] << std::endl;
	}
	catch (const OutOfRange &e)
	{
		std::cout << e.what() << std::endl;
	}
	x *= 2;
	try
	{
		std::cout << std::endl;
		std::cout << "At index " << x << " -> " << moh[x] << std::endl;
	}
	catch (const OutOfRange &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
