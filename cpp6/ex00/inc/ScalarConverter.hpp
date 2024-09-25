#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#define IMP "impossible"
#define NAN "nan"
#define NDIS "Non displayable"

# include <cctype>
# include <iostream>
# include <string>

class ScalarConverter
{
  public:
	static void convert(std::string& str);

  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static int makeConversion(std::string str);
	static void removeLeadingSacpesAndZeros(std::string& str);
	static void formatDisplay(std::string& str, int index);
	static void display(void);
	static bool isInteger(const std::string& str);
	static bool isCharacter(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);
	static bool overflowing(long double nb, int type);
	static std::string getNumStr(int printTo);

	static int static_type;
	static double static_nb;
	static const char* typeDisplay[4];
};

#endif // !SCALARCONVERTER_HPP
