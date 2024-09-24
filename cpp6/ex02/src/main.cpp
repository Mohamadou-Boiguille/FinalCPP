#include "../inc/Abc.hpp"

Base *generate(void)
{
	std::srand(std::time(0));
	int nb = (std::rand() % 3) + 1;
	std::cout << static_cast<char>('A' - 1 + nb) << ' ';
	std::cout << "class generated." << std::endl;
	if (nb == 1)
		return new A();
	else if (nb == 2)
		return new B();
	return new C();
}

void identify(Base *p)
{
	if (p == NULL)
		std::cout << "is NULL" << std::endl;
	try
	{
		if (dynamic_cast<A *>(p))
		{
			std::cout << "is A class" << std::endl;
			return;
		}
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		if (dynamic_cast<B *>(p))
		{
			std::cout << "is B class" << std::endl;
			return;
		}
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		if (dynamic_cast<C *>(p))
		{
			std::cout << "is C class" << std::endl;
			return;
		}
	}
	catch (const std::exception &e)
	{
	}
	std::cout << "is not an A, B or C class";
}

void identify(Base &p)
{
	identify(&p);
}

int main(void)
{
	Base *random = generate();
	identify(random);
	delete random;
	return 0;
}
