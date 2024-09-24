#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <limits>
#include <string>
#include <cstdlib>
#include <cfloat>

#define CHR 1
#define INT 2
#define DBL 3
#define FLT 4
#define NONE 5
#define NANNB 6
#define NINF 7
#define PINF 8

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(std::string str)
{
	typeDisplay[1] = "int\t: ";
	typeDisplay[0] = "char\t: ";
	typeDisplay[2] = "double\t: ";
	typeDisplay[3] = "float\t: ";
	this->removeLeadingSacpesAndZeros(str);
	std::cout << "test : |" << str << "|" << sizeof(double)  << "|" << sizeof(long double)<< std::endl;
	this->type = this->convert(str);
    this->display();
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  if (this != &other) {
  }
  return *this;
}

void ScalarConverter::removeLeadingSacpesAndZeros(std::string& str)
{
    size_t firstNonSpace = str.find_first_not_of(' ');
    if (firstNonSpace != std::string::npos) {
        str = str.substr(firstNonSpace);
    } else {
        str.clear();
    }
    size_t firstNonZero = str.find_first_not_of('0');
    if (firstNonZero != std::string::npos) {
        str = str.substr(firstNonZero);
    } else {
        str = str.substr(str.length() - 1);
    }
}

std::string ScalarConverter::getNumStr(int printTo)
{
	std::ostringstream oss;
	if (this->type == NANNB && printTo >= DBL)
		return "nan";
	if (this->type == PINF && printTo >= DBL)
		return "+inf";
	if (this->type == NINF && printTo >= DBL)
		return "-inf";
	if (this->type == NANNB || this->type == PINF || this->type == NINF)
		return "impossible";
	if (this->type == NONE)
		return "impossible";
	if (printTo == INT) {
		if (overflowing(this->nb, INT))
			return "impossible";
		oss << static_cast<int>(this->nb);
	} 
	else if (this->nb == 0)
		oss << "0";
	else if (printTo == CHR) {
		if (this->nb > 127 || this->nb < 0)
			return "impossible";
		if (isprint(static_cast<char>(this->nb)))
			oss << static_cast<char>(this->nb);
		else
			return "not displayable";
	} else if (printTo == DBL) {
		if (overflowing(this->nb, DBL))
			return "impossible";
		oss << std::setprecision(15) << static_cast<double>(this->nb);
	} else if (printTo == FLT) {
		if (overflowing(this->nb, FLT))
			return "impossible";
		oss << std::setprecision(6) << static_cast<float>(this->nb);
	}
	return oss.str();
}

void ScalarConverter::formatDisplay(std::string& str, int index) {
	if (index <= INT || str == "impossible")
		return;
    size_t zeroPosition = str.find_last_not_of('0');
    if (str.find('.') != std::string::npos && zeroPosition != std::string::npos) {
        if (zeroPosition == str.size() - 1 && str[zeroPosition] == '0') {
            return;
        }
        str.erase(zeroPosition + 1);
    }
	if (this->type <= FLT && index >= DBL && str.find('.') == std::string::npos)
		str += ".0";
	if (index == FLT)
		str += "f";
}

void ScalarConverter::display()
{
	std::string numStr;

	for(int i = 1; i <= 4; i++)
	{
		numStr = getNumStr(i);
		formatDisplay(numStr, i);
		std::cout << this->typeDisplay[i - 1];
		std::cout << numStr;
		std::cout << std::endl;
	}
}

bool ScalarConverter::overflowing(long double nb, int type)
{
	if (type == CHR && nb >= 0 && nb <= 127)
			return true;
	if (type == INT)
	{
		if (nb > std::numeric_limits<int>::max()
			|| nb < std::numeric_limits<int>::min())
			return true;
	}
	if (type == DBL)
	{    if (std::isnan(nb) || std::isinf(nb))
			return true;
		if (nb > std::numeric_limits<double>::max()
			|| nb < std::numeric_limits<double>::min())
			return true;
	}
	if (type == FLT)
	{
	    if (std::isnan(nb) || std::isinf(nb))
			return true;
		if (nb > std::numeric_limits<float>::max()
			|| nb < std::numeric_limits<float>::min())
			return true;
	}
	return false;
}

bool	isValidNb(const std::string& str)
{
	int fTerminated = 0;
	bool dotSeen = false;
	std::string::const_iterator it = str.begin();
	if (str.find('.') && str[str.length() - 1] == 'f')
		fTerminated = 1;
	if (it != str.end() && *it == '-')
		++it;
    while (it != str.end() - fTerminated  && (std::isdigit(*it) || *it == '.'))
	{
		if (*it == '.' && dotSeen)
			return (false);
		if (*it == '.')
			dotSeen = true;
		++it;
	}
    return !str.empty() && it == str.end() - fTerminated;
}

char ScalarConverter::convert(std::string& str)
{
	if (str == "-inf" || str == "-inff")
		return NINF;
	if (str == "+inf" || str == "+inff")
		return PINF;
	if (str == "nan" || str == "nanf")
		return NANNB;
	if (str.find_first_not_of('0') == std::string::npos)
	{
		this->nb = 0;
		return INT;
	}
	if (this->isCharacter(str))
		return CHR;
	if (isValidNb(str) == false)
		return NONE;
	if (this->isInteger(str))
		return INT;
	if (this->isDouble(str))
		return DBL;
	if (this->isFloat(str))
		return FLT;
	return NONE;
}

bool ScalarConverter::isCharacter(const std::string& str) {
	if (str.at(0) == '\'' && str.at(2) == '\'' && str.length() == 3)
	{
		this->nb = static_cast<double>(str.at(1));
		return true;
	}	
	if ((str.length() == 1 && !isdigit(str.at(0))))
	{
		this->nb = static_cast<double>(str[0]);
		return true;
	}
	return false;
}

bool ScalarConverter::isInteger(const std::string& str) {
    long int num;
	char remain;
    std::istringstream iss(str);

    iss >> num;
	if (iss >> remain || overflowing(num, INT))
		return false;
	this->nb = static_cast<double>(num);
	return true;
}

bool ScalarConverter::isDouble(const std::string& str) {
	if (str.find('.') == std::string::npos)
		return false;
    std::istringstream iss(str);
    long double num;
    iss >> num;
	if (overflowing(num, DBL))
		return false;
	if (!iss.eof())
		return false;
	this->nb = num;
	return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
	if (str.find('.') == std::string::npos)
		return false;
    std::istringstream iss(str);
    long double num;
	char remain;
    iss >> num;
	iss >> remain;
	if (remain != 'f' || overflowing(num, FLT) || iss >> remain)
		return false;
	this->nb = static_cast<double>(num);
	return true;
}
