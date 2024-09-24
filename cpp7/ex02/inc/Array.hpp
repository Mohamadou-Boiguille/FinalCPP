#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <algorithm>
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

template <typename T, unsigned int N>
class Array
{
  public:
	Array()
	{
		myArray = new T[N];
		std::fill(myArray, myArray + N, T());
	};
	Array(unsigned int size)
	{
		myArray = new T[N];
		std::fill(myArray, myArray + N, T());
		if (size >= N)
			throw OutOfRange();
	};
	Array(const Array &other)
	{
		myArray = new T[N];
		std::copy(other.myArray, other.myArray + N, myArray);
	};
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] myArray;
			myArray = new T[N];
			std::copy(other.myArray, other.myArray + N, myArray);
		}
		return *this;
	};
	~Array()
	{
		delete[] myArray;
	};
	unsigned int size(void)
	{
		return N;
	};
	T &operator[](unsigned int index)
	{
		if (index >= N)
			throw OutOfRange();
		return this->myArray[index];
	};
	const T &operator[](unsigned int index) const
	{
		if (index >= N)
			throw OutOfRange();
		return this->myArray[index];
	};

  private:
	T *myArray;
};

#endif // !ITER_HPP
