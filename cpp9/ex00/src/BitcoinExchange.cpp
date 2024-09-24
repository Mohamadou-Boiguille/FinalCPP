#include "../inc/BitcoinExchange.hpp"
#include <cctype>
#include <cstring>
#include <exception>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(char *filename)
	: _inputFileName(filename), _dbFileName("data.csv")
{
	try
	{
		parseFile(DB);
		parseFile(INPUT);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

bool BitcoinExchange::parseFile(bool type)
{
	std::string line;
	const char *fileName;
	std::ifstream file;
	struct stat fileChecker;

	if (type == INPUT)
		fileName = _inputFileName;
	else if (type == DB)
		fileName = _dbFileName.c_str();
	file.open(fileName);
	if (stat(fileName, &fileChecker) != 0 || !(fileChecker.st_mode & S_IFREG) || !file.is_open())
		throw std::runtime_error("file opening failed.");
	getline(file, line);
	while (std::getline(file, line))
	{
		if (type == INPUT)
			evaluateInputLine(line);
		else if (type == DB)
			storeNewValueFromDB(line);
	}
	file.close();
	if (_stockAtDate.empty())
		throw std::runtime_error("db empty.");
	return (true);
}

bool BitcoinExchange::storeNewValueFromDB(std::string line)
{
	int date = 0;
	float value = 0;

	if (line.at(4) != '-')
		return logErrors(BAD_FORMAT);
	if (line.empty() || line.length() < 11 || line.at(7) != '-' || line.at(10) != ',')
		return logErrors(BAD_FORMAT);
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(line.at(i)))
			return logErrors(BAD_FORMAT);
		else
			date = date * 10 + line.at(i) - '0';
	}
	if (isValidDate(date) == false)
		return logErrors(BAD_DATE);
	std::istringstream iss(line.substr(11));
	if (!(iss >> value))
		return logErrors(CAST_ERROR);
	_stockAtDate.insert(std::make_pair(date, value));
	return true;
}

bool BitcoinExchange::evaluateInputLine(std::string line)
{
	int date = 0;
	float value = 0;

	if (line.at(4) != '-')
		return logErrors(BAD_FORMAT);
	if (line.empty() || line.length() < 14 || line.at(7) != '-' || line.at(11) != '|')
		return logErrors(BAD_FORMAT);
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(line.at(i)))
			return logErrors(line);
		else
			date = date * 10 + line.at(i) - '0';
	}
	// date avant le bitcoin
	if (isValidDate(date) == false)
		return logErrors(line);
	std::istringstream iss(line.substr(13));
	if (!(iss >> value))
		return logErrors(CAST_ERROR);
	if (value < 0)
		return logErrors(NOT_POSITIVE);
	if (value > 100)
		return logErrors(TOO_LARGE);
	std::map<int, float>::iterator it = _stockAtDate.lower_bound(date);
	if (it->first != date && it != _stockAtDate.begin())
		it--;
	std::cout << formatDate(it->first) << " => " << value << " = " << value * it->second << std::endl;
	return true;
}

std::string BitcoinExchange::formatDate(int date)
{
	int year = date / 10000;
	int month = (date / 100) % 100;
	int day = date % 100;

	std::ostringstream oss;
	oss << year << "-" << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day;

	return oss.str();
}

bool BitcoinExchange::logErrors(std::string errorMsg)
{
	if (std::isdigit(errorMsg.at(0)))
		std::cerr << "Error: bad input => " << errorMsg.substr(0, 10) << std::endl;
	else
		std::cerr << "Error: " << errorMsg << std::endl;
	return false;
}

void BitcoinExchange::displayMap()
{
	// pour debug
	std::map<int, float>::iterator it;
	for (it = _stockAtDate.begin(); it != _stockAtDate.end(); ++it)
	{
		std::pair<int, float> current = *it;
		std::cout << "date: " << current.first << " - value: " << current.second << std::endl;
	}
}

bool BitcoinExchange::isValidDate(int date)
{
	int day = date % 100;
	date /= 100;
	int month = date % 100;
	date /= 100;
	int year = date;
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (month < 1 || month > 12)
		return false;
	int daysInFebruary = isLeapYear ? 29 : 28;
	int daysInMonth[] = {0, 31, daysInFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > daysInMonth[month])
		return false;
	if (year < 2008)
		return false;
	return true;
}

// Constructor et desctructor
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
