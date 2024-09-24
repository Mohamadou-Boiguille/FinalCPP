#ifndef RPN_HPP

#define SEPARATOR "----------------------------------------"
#include <iostream>
#include <stack>

class RPN
{
  public:
	RPN();
	RPN(bool defense);
	RPN(std::string inputStr);
	~RPN();
	void calculate(const std::string inputStr);

  private:
	long long processOperation(const char inputStr);
	std::stack<int> _input;
	bool _defense;
};

#endif // !RPN_HPP
