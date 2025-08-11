#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <numeric>

class Span
{
	public:

		Span();
		Span(size_t n);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& other);

		void 	addNumber(int num);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		size_t	shortestSpan();
		size_t	longestSpan();

	private:

		std::vector<int>	_span;
		size_t				_max_size;

};

