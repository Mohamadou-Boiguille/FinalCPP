#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	  private:
		T *ptr;

	  public:
		iterator(T *p)
			: ptr(p)
		{
		}

		iterator &operator++()
		{
			++ptr;
			return *this;
		}
		iterator &operator--()
		{
			--ptr;
			return *this;
		}
		bool operator==(iterator other) const
		{
			return *ptr == *other.ptr;
		}
		bool operator!=(iterator other) const
		{
			return !(*this == other);
		}
		T &operator*() const
		{
			return *ptr;
		}
	};
	iterator begin()
	{
		return iterator(&(std::stack<T>::top()) - (std::stack<T>::size() - 1));
	};
	iterator end()
	{
		return iterator(&(MutantStack<T>::top()));
	};

  private:
	T *ptr;
};

#endif // !MUTANTSTACK_HPP
