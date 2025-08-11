#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
#include <limits.h>

void				printList(std::vector<int>& list, size_t size);
std::string			setFixedPrecision(int prec, double num);
std::vector<size_t>	jacobsthalSequence(size_t n);
void				vectorSort(std::vector<int>& list);
void				dequeSort(std::deque<int>& list);
void				vecFordJohnson(std::vector<int>& list);
void				deqFordJohnson(std::deque<int>& list);

template <typename Container>
void	parseInput(int argc, char **argv, Container& list)
{
	std::set<int> seen;
	for (int i = 1; i < argc; ++i)
	{
		std::string	token(argv[i]);
		for (size_t i = 0; i < token.size(); ++i)
			if(!std::isdigit(token[i]) && token[i] != ' ')
				throw std::invalid_argument("Invalid input");
		std::stringstream oss(argv[i]);
		std::string num;
		while (oss >> num)
		{
			int value = std::stoi(num);

			if (seen.insert(value).second == false)
				throw std::invalid_argument("Duplicates not allowed");
			list.push_back(value);
		}
	}
}

template <typename Func>
double	funcTime(Func func)
{
	double result;
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	func();
	gettimeofday(&end, NULL);
	result = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1e6);
	return (result);
}

template <typename Container>
void	mergeInsertSort(Container& list)
{
	if (list.size() <= 1)
		return;

	Container A_list;
	Container B_list;

	for (typename Container::iterator it = list.begin(); it != list.end(); ++it)
    {
		typename Container::iterator next = it;
		++next;
		if (next == list.end())
			break;
		if (*it < *next)
		{
			A_list.push_back(*it);
			B_list.push_back(*next);
		}
    	else
		{
			B_list.push_back(*it);
			A_list.push_back(*next);
		}
		it = next;
	}

	if (list.size() % 2 != 0)
		A_list.push_back(list.back());

	mergeInsertSort(A_list);

	typename Container::iterator insert_pos;

	// Linear insert
	// for(size_t i = 0; i < B_list.size(); ++i)
	// {
	// 	insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[i]);
	// 	A_list.insert(insert_pos, B_list[i]);
	// }

	// Jacobsthal insert
	std::vector<bool> inserted(B_list.size(), false);
	std::vector<size_t> insert_order = jacobsthalSequence(B_list.size());
	for (size_t i = 0; i < insert_order.size(); ++i) 
	{
		size_t index = insert_order[i];
		if (!inserted[index])
		{
			insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[index]);
			A_list.insert(insert_pos, B_list[index]);
			inserted[index] = true;
		}
	}
	for (size_t i = 0; i < B_list.size(); ++i)
	{
		if (!inserted[i])
		{
			insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[i]);
			A_list.insert(insert_pos, B_list[i]);
			inserted[i] = true;
		}
	}

	list = A_list;
}
