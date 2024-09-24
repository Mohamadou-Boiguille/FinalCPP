#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

PmergeMe::PmergeMe(char **inputArray)
	: _listSize(0), _sortStart(0), _sortEnd(0)
{
	try
	{
		convertInputToList(inputArray);
		_listSize = _nbList.size();
		displayList(BEFORE, _nbList);
		_sortStart = getCurrentTime();
		mergeInsertionSort(_nbList);
		_sortEnd = getCurrentTime();
		displayList(AFTER, _nbList);
		displayTime(LIST);
		_sortStart = getCurrentTime();
		mergeInsertionSortDeque(_dequeList);
		_sortEnd = getCurrentTime();
		displayTime(DEQUE);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void PmergeMe::mergeInsertionSort(std::list<int> &toMergeInsert)
{
	std::list<int> leftHalf, rightHalf;
	if (toMergeInsert.size() <= 2)
	{
		if (toMergeInsert.size() <= 2 && toMergeInsert.front() > toMergeInsert.back())
			std::swap(toMergeInsert.front(), toMergeInsert.back());
		return;
	}
	std::list<int>::iterator middle = toMergeInsert.begin();
	std::advance(middle, toMergeInsert.size() / 2);
	leftHalf.splice(leftHalf.begin(), toMergeInsert, toMergeInsert.begin(), middle);
	rightHalf.splice(rightHalf.begin(), toMergeInsert, toMergeInsert.begin(), toMergeInsert.end());
	mergeInsertionSort(leftHalf);
	mergeInsertionSort(rightHalf);
	while (!leftHalf.empty() && !rightHalf.empty())
	{
		if (leftHalf.front() < rightHalf.front())
		{
			toMergeInsert.push_back(leftHalf.front());
			leftHalf.pop_front();
		}
		else
		{
			toMergeInsert.push_back(rightHalf.front());
			rightHalf.pop_front();
		}
	}
	toMergeInsert.splice(toMergeInsert.end(), leftHalf);
	toMergeInsert.splice(toMergeInsert.end(), rightHalf);
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &toMergeInsert)
{
	std::deque<int> leftHalf, rightHalf;
	if (toMergeInsert.size() <= 2)
	{
		if (toMergeInsert.size() == 2 && toMergeInsert.front() > toMergeInsert.back())
			std::swap(toMergeInsert.front(), toMergeInsert.back());
		return;
	}
	std::deque<int>::iterator middle = toMergeInsert.begin() + toMergeInsert.size() / 2;
	leftHalf.insert(leftHalf.begin(), toMergeInsert.begin(), middle);
	rightHalf.insert(rightHalf.begin(), middle, toMergeInsert.end());
	mergeInsertionSortDeque(leftHalf);
	mergeInsertionSortDeque(rightHalf);

	std::deque<int> result;
	std::deque<int>::iterator leftIt = leftHalf.begin();
	std::deque<int>::iterator rightIt = rightHalf.begin();
	while (leftIt != leftHalf.end() && rightIt != rightHalf.end())
	{
		if (*leftIt < *rightIt)
		{
			result.push_back(*leftIt);
			++leftIt;
		}
		else
		{
			result.push_back(*rightIt);
			++rightIt;
		}
	}
	result.insert(result.end(), leftIt, leftHalf.end());
	result.insert(result.end(), rightIt, rightHalf.end());
	toMergeInsert = result;
}

void PmergeMe::displayList(std::string beforeOrAfter, std::list<int> listToDisplay)
{
	std::cout << beforeOrAfter;
	for (std::list<int>::iterator it = listToDisplay.begin(); it != listToDisplay.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displayTime(std::string containerType)
{
	std::cout << "Time to process a range of \t" << _listSize << " elements with " << containerType << (_sortEnd - _sortStart) / 1000000.0 << " us" << std::endl;
}

void PmergeMe::convertInputToList(char **inputArray)
{
	for (size_t i = 0; inputArray[i]; i++)
	{
		char *ptrEndStr;
		long long int value = strtol(inputArray[i], &ptrEndStr, 10);
		if (*ptrEndStr != '\0')
			throw std::runtime_error("Bad format of a number");
		else
		{
			if (value >= INT_MIN && value <= INT_MAX)
			{
				_nbList.push_back(static_cast<int>(value));
				_dequeList.push_back(static_cast<int>(value));
			}
			else
				throw std::runtime_error("Overflow from a number");
		}
	}
}

long long PmergeMe::getCurrentTime()
{
	struct timespec currentTime;
	if (clock_gettime(CLOCK_REALTIME, &currentTime) != 0)
		throw std::runtime_error("clock_gettime failed");
	long long currentTimeNs = static_cast<long long>(currentTime.tv_sec) * 1000000000LL + static_cast<long long>(currentTime.tv_nsec);
	return currentTimeNs;
}

PmergeMe::~PmergeMe()
{
}
