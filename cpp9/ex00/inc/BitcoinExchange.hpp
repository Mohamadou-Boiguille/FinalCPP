#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BAD_FORMAT "bad format."
#define BAD_DATE "invalid date."
#define CAST_ERROR "cast error."
#define INPUT true
#define DB false
#define DB_NAME "data.csv"
#define NOT_POSITIVE "not a positive number."
#define TOO_LARGE "too large number."

typedef struct s_date
{
	int year;
	int month;
	int day;
} t_date;

class BitcoinExchange
{
  public:
	BitcoinExchange(char *filename);
	~BitcoinExchange();

  private:
	// variables
	char *_inputFileName;
	std::string _dbFileName;
	std::map<int, float> _stockAtDate;
	// fonctions
	BitcoinExchange();
	bool parseFile(bool type);
	bool evaluateInputLine(std::string line);
	std::string formatDate(int date);
	bool isValidDate(int date);
	bool customCompare(const std::pair<int, double> &database, int date);
	bool storeNewValueFromDB(std::string line);
	bool logErrors(std::string errorMsg);
	void displayMap(); // pour debug
};
#endif // !BITCOINEXCHANGE_H
