#include "../inc/RPN.hpp"
#include <algorithm>
#include <climits>
#include <cstring>
#include <sstream>
#include <string>

// constructeurs destructeurs
RPN ::RPN()
{
}

RPN ::RPN(bool defense)
	: _defense(defense)
{
}

RPN ::RPN(std::string inputStr)
{
	calculate(inputStr);
}

RPN ::~RPN()
{
}

// autres
long long RPN ::processOperation(const char operators)
{
	long long value = _input.top();
	_input.pop();
	if (_defense)
		std::cout << _input.top() << " " << operators << " " << value << std::endl;
	if (operators == '+')
		value += _input.top();
	else if (operators == '-')
		value = _input.top() - value;
	else if (operators == '*')
		value *= _input.top();
	else if (operators == '/')
		value = _input.top() / value;
	if (value < INT_MIN || value > INT_MAX)
		throw std::runtime_error("Overflow.");
	_input.pop();
	_input.push(value);
	return value;
}

void RPN::calculate(const std::string inputStr)
{
	while (!_input.empty())
		_input.pop();
	try
	{
		if (inputStr.empty())
			throw std::runtime_error("Empty input");

		std::stringstream ss(inputStr);
		std::string token;
		std::string validChars = "1234567890-+*/";
		std::string operators = "-+*/";

		while (ss >> token)
		{
			if (token.length() != 1)
				throw std::runtime_error("Bad item length.");
			if (validChars.find(token.at(0)) == std::string::npos)
				throw std::runtime_error("Invalid character.");
			if (operators.find(token.at(0)) != std::string::npos)
			{
				if (token.at(0) == '/' && _input.top() == 0)
					throw std::runtime_error("Divide by zero is impossible.");
				if (_input.size() < 2)
					throw std::runtime_error("Syntax.");
				processOperation(token.at(0));
			}
			else
				_input.push(token.at(0) - '0');
		}
		if (_input.size() != 1)
			throw std::runtime_error("Bad number of operators or operands.");
		std::cout << "Result is : " << _input.top() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
