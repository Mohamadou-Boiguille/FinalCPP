#include "../inc/iter.hpp"

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Int array: " << std::endl;
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;
	std::cout << "use incrementElement()" << std::endl;
	iter(intArray, intArraySize, incrementElement<int>);
	std::cout << "New array: " << std::endl;
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Double array: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	std::string stringArray[] = {"Hello", "World", "!"};
	size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "String array: ";
	iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;
}
