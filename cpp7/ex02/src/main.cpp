#include "../inc/Array.hpp"
#include <iostream>
#include <stdlib.h>

int main(void)
{
	int myArrlen = rand() % 12 + 5;
	int index = myArrlen / 3;

	std::cout << "Create Array:\n" << std::endl;
	Array<int> myArr(myArrlen);

	std::cout << "Filling an array of size " << myArr.size() << ":\n"
			  << std::endl;
	for (int i = 0; i < myArrlen; i++)
	{
		try
		{
			myArr[i] = rand() % 100 + 1;
			std::cout << myArr[i] << " ";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n\nTesting access to array :\n"
			  << std::endl;

	for (int i = 0; i < myArrlen; i++)
	{
		try
		{
			std::cout << myArr[i] << " ";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n\nTesting access to indexes :" << std::endl;
	try
	{
		std::cout << std::endl;
		std::cout << "At index " << index << " -> " << myArr[index] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	index *= 2;
	try
	{
		std::cout << std::endl;
		std::cout << "At index " << index << " -> " << myArr[index] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Create empty Array:\n" << std::endl;
	Array<int> secondArr;
	std::cout << "\n\nTesting access to array :\n"
			  << std::endl;
	try
	{		
		std::cout << "At index " << index << " -> " << secondArr[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{		
		std::cout << "At index " << index << " -> " << secondArr[1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
