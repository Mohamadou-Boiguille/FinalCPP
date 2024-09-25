#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>

class OutOfRange : public std::exception
{
  public:
	const char *what() const throw()
	{
		return "Index out of range";
	}
};

template <typename T>
class Array
{
  public:
	Array()
	{
		myArray = new T[0];
		size = 0
	};
	Array(unsigned int size)
	{
		if (size == 0)
			throw OutOfRange();
		myArray = new T[size];
		std::fill(myArray, myArray + size, T());
	};
	Array(const Array &other)
	{
		myArray = new T[other.size];
		std::copy(other.myArray, other.myArray + other.size(), myArray);
	};
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] myArray;
			myArray = new T[other.size];
			std::copy(other.myArray, other.myArray + other.size(), myArray);
		}
		return *this;
	};
	~Array()
	{
		delete[] myArray;
	};
	unsigned int size(void)
	{
		return sizeof(myArray);
	};
	T &operator[](unsigned int index)
	{
		if (index >= this->size())
			throw OutOfRange();
		return this->myArray[index];
	};
	const T &operator[](unsigned int index) const
	{
		if (index >= this->size())
			throw OutOfRange();
		return this->myArray[index];
	};

  private:
	T *myArray;
	unsigned int size;
};

#endif
