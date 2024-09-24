#include "../inc/Serializer.hpp"
#include <iostream>

int main(void)
{
	// Data *original = NULL;
	Data *original = new Data;
	original->name = "Mohamadou";
	original->login = "moboigui";
	original->level = 8;
	Serializer converter = Serializer();
	uintptr_t serialized = converter.serialize(original);
	Data *converted = converter.deserialize(serialized);
	if (original)
	{
		std::cout << "original : " << original << std::endl;
		std::cout << original->name + " " << original->login + " " << original->level << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "serialized = " << serialized << std::endl;
	std::cout << "--------------------" << std::endl;
	if (converted)
	{
		std::cout << "converted : " << converted << std::endl;
		std::cout << converted->name + " " << converted->login + " " << converted->level << std::endl;
	}
	delete original;
	return 0;
}
