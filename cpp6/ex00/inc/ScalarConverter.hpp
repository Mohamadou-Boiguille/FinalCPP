#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#define IMP "impossible"
#define NAN "nan"
#define NDIS "Non displayable"

# include <algorithm>
# include <cctype>
# include <iostream>
# include <string>

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter(std::string str);

  private:
	void removeLeadingSacpesAndZeros(std::string& str);
	void formatDisplay(std::string& str, int index);
	void display(void);
	char convert(std::string& str);
	bool isInteger(const std::string& str);
	bool isCharacter(const std::string& str);
	bool isFloat(const std::string& str);
	bool isDouble(const std::string& str);
	bool overflowing(long double nb, int type);
	std::string getNumStr(int printTo);
	int		type;
	double nb;
	const char * typeDisplay[4];
};
#endif // !SCALARCONVERTER_HPP
