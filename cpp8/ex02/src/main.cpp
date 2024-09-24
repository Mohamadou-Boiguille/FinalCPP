#include "../inc/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = " << mstack.size() << std::endl;
	// std::cout << "begin = " << mstack.begin() << std::endl;
	// std::cout << "end = " << mstack.end() << std::endl;
	mstack.push(3);
	mstack.push(7);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "begin-> " << *it << std::endl;
	std::cout << "end-> " << *ite << std::endl;
	std::cout << "first loop -> " << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mstack.begin();
	++it;
	--it;
	std::cout << "second loop -> " << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	for (int i = 0; i < 5; i++)
		++it;
	std::cout << *it << std::endl;
	std::stack<int> s(mstack);
	return 0;
}
