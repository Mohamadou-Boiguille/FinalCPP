#ifndef PMERGEME_HPP

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <list>

#define BEFORE "Before :\t"
#define AFTER "After  :\t"
#define LIST "std::list  :\t"
#define DEQUE "std::deque :\t"

class PmergeMe
{
  public:
	PmergeMe(char **inputArray);
	~PmergeMe();

  private:
	// functions
	PmergeMe();
	void mergeInsertionSort(std::list<int> &toMergeInsert);
	void displayList(std::string beforeOrAfter, std::list<int> listToDisplay);
	void displayTime(std::string container);
	void convertInputToList(char **inputArray);
	void mergeInsertionSortDeque(std::deque<int> &toMergeInsert);
	long long getCurrentTime();
	// variables
	std::list<int> _nbList;
	std::deque<int> _dequeList;
	int _listSize;
	long long _sortStart;
	long long _sortEnd;
};
#endif // !PMERGEME_HPP
