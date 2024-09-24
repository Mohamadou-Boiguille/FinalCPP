#ifndef ITER_HPP
#define HPP

#include <iostream>
#include <cstddef>

template<typename T>
void iter(T array[], size_t size, void (*func)(T&))
{
	for(size_t i = 0; i < size; i++)
		(*func)(array[i]);
}

template<typename T>
void iter(const T array[], size_t size, void (*func)(const T&))
{
	for(size_t i = 0; i < size; i++)
		(*func)(array[i]);
}

template<typename T>
void incrementElement(T& item)
{
	item += 1;
}

template <typename T>
void printElement(T &element)
{
	std::cout << element << " ";
}

#endif // !ITER_HPP
