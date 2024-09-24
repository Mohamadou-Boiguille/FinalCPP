#include "../inc/PmergeMe.hpp"
#include <cstring>
#include <iostream>
#include <limits>
#include <optional>

typedef struct s_manualInput
{
	size_t items;
	long long min;
	long long max;
	std::string itemsStr;
	std::string minStr;
	std::string maxStr;
	char **nbList;
} t_manualInput;

int createRandomNbList(t_manualInput &mInput)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	mInput.nbList = new char *[mInput.items + 1];
	if (!mInput.nbList)
		return false;
	mInput.nbList[0] = new char[mInput.maxStr.length() + 1];
	mInput.nbList[1] = new char[mInput.minStr.length() + 1];
	if (!mInput.nbList[0] || !mInput.nbList[1])
		return false;
	strcpy(mInput.nbList[0], mInput.maxStr.c_str());
	strcpy(mInput.nbList[1], mInput.minStr.c_str());
	for (size_t i = 2; i < mInput.items; ++i)
	{
		char buffer[30];
		int randomNumber = mInput.min + std::rand() % (mInput.max - mInput.min + 1);
		sprintf(buffer, "%d", randomNumber);
		mInput.nbList[i] = new char[strlen(buffer) + 1];
		if (!mInput.nbList[i])
			return false;
		strcpy(mInput.nbList[i], buffer);
	}
	mInput.nbList[mInput.items] = NULL;
	return true;
}

int errorOnStdInput(std::string &stdInput)
{
	if ((!(std::cin >> stdInput) && std::cin.eof()) || stdInput.at(0) == 'q')
	{
		std::cerr << "Exit program." << std::endl;
		return 2;
	}
	if (!(std::cin))
	{
		std::cerr << "Error: Input invalid - RESTART." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	return (0);
}

void printErrorIfInvalidInput(t_manualInput &mInput, unsigned inputNb, const char *ptrEnd)
{
	if (inputNb == 1 && (*ptrEnd != '\0' || mInput.items < 2))
	{
		std::cerr << mInput.itemsStr << ": Bad format for quantity, put to 100." << std::endl;
		mInput.items = 100;
	}
	else if (inputNb == 2 && *ptrEnd != '\0')
	{
		std::cerr << mInput.minStr << ": Bad format, put to INT_MIN but your value will be on the input." << std::endl;
		mInput.min = INT_MIN;
	}
	else if (inputNb == 3 && (*ptrEnd != '\0' || mInput.min > mInput.max))
	{
		if (mInput.min > mInput.max)
		{
			std::cerr << "The minimum value is greater than the maximum value, swap values." << std::endl;
			std::swap(mInput.min, mInput.max);
		}
		else
		{
			std::cerr << mInput.maxStr << ": Bad format, put to INT_MAX but your value will be on the input." << std::endl;
			mInput.max = INT_MIN;
		}
	}
}

int getManualInput(t_manualInput &mInput)
{
	char *ptrEnd;
	int errorCode = 0;

	std::cout << "How many numbers do you wan't to sort ? (q to quit)\t";
	errorCode = errorOnStdInput(mInput.itemsStr);
	if (errorCode)
		return errorCode;
	mInput.items = strtoll(mInput.itemsStr.c_str(), &ptrEnd, 10);
	printErrorIfInvalidInput(mInput, 1, ptrEnd);
	std::cout << "What will be the minimum value ?        (q to quit)\t";
	errorCode = errorOnStdInput(mInput.minStr);
	if (errorCode)
		return errorCode;
	mInput.min = strtoll(mInput.minStr.c_str(), &ptrEnd, 10);
	printErrorIfInvalidInput(mInput, 2, ptrEnd);
	std::cout << "What will be the maximum value ?        (q to quit)\t";
	errorCode = errorOnStdInput(mInput.maxStr);
	if (errorCode)
		return errorCode;
	mInput.max = strtoll(mInput.maxStr.c_str(), &ptrEnd, 10);
	printErrorIfInvalidInput(mInput, 3, ptrEnd);
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3000)
	{
		std::cerr << "Wrong nb of arguments." << std::endl;
		return 1;
	}
	std::string firstArg = argv[1];
	if (!firstArg.compare("defense"))
	{
		while (true)
		{
			std::cout << "==================================================" << std::endl;
			std::cout << "=                  PmergeMe GUI                  =" << std::endl;
			std::cout << "==================================================" << std::endl;
			t_manualInput mInput;
			int manualInputErrorValue = getManualInput(mInput);
			if (manualInputErrorValue < 0)
				continue;
			if (manualInputErrorValue > 0)
				return manualInputErrorValue;
			if (createRandomNbList(mInput) == false)
			{
				std::cerr << "Error: creating random nb list" << std::endl;
			}
			else
			{
				std::cout << "\n================= Launch Program =================" << std::endl;
				PmergeMe defense(mInput.nbList);
				for (size_t i = 0; i < mInput.items; i++)
					delete[] mInput.nbList[i];
				delete[] mInput.nbList;
			}
			std::cout << std::endl;
		}
	}
	else
		PmergeMe sort(argv + 1);
	return 0;
}
