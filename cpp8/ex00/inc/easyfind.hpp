#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class NotFound : public std::exception
{
  public:
	const char *what() const throw()
	{
		return "Element not found";
	}
};

template <typename T>
typename T::iterator easyfind(T &toFind, int n)
{
	typename T::iterator it = toFind.begin();
	while (it != toFind.end())
	{
		if (static_cast<int>(*it) == n)
			return it;
		it++;
	}
	throw NotFound();
}

#endif // !EASYFIND_HPP
