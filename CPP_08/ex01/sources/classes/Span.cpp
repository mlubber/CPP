#include "../../headers/Span.hpp"

Span::Span(): _max_size(100)
{
	// std::cout << "default constructor" << std::endl;
	_span.reserve(_max_size);
}
Span::Span(size_t n): _max_size(n)
{
	// std::cout << "param constructor" << std::endl;
	_span.reserve(_max_size);
}
Span::Span(const Span& other) : _span(other._span), _max_size(other._max_size)
{
	// std::cout << "copy constructor" << std::endl;
}
Span::~Span()
{
	// std::cout << "default destructor" << std::endl;
}

Span&	Span::operator=(const Span& other)
{
	// std::cout << "copy assignment operator" << std::endl;
	if (this != &other)
	{
		_span = other._span;
		_max_size = other._max_size;
	}
	return (*this);
}

void 	Span::addNumber(int num)
{
	if (_span.size() >= _max_size)
		throw std::runtime_error("Span is full");
	_span.push_back(num);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t range = std::distance(begin, end);
	if (_span.size() + range > _max_size)
		throw std::runtime_error("Not enough space in span for range");
	_span.insert(_span.end(), begin, end);
}

size_t	Span::shortestSpan()
{
	if (_span.size() < 2)
		throw std::runtime_error("Needs more elements");
	
	std::vector<int> sorted_span = _span;
	std::sort(sorted_span.begin(), sorted_span.end());

	std::vector<int> diffs(sorted_span.size());
	std::adjacent_difference(sorted_span.begin(),sorted_span.end(), diffs.begin());
	
	// /*PRINT*/
	// int i = 1;
	// for (std::vector<int>::iterator it = sorted_span.begin() + 1; it != sorted_span.end(); ++it, ++i)
	// 	std::cout << *it << "	-	" << *(it - 1) << "	=	" << (*it) - (*(it - 1)) << "	(" << diffs[i] << ")" << "\n";
	// std::cout << "\nShortest span: ";

	std::vector<int>::iterator it_min = std::min_element(diffs.begin() + 1, diffs.end());
	int min = *it_min;
	return (static_cast<size_t>(min));
}


size_t	Span::longestSpan()
{
	if (_span.size() < 2)
		throw std::runtime_error("Needs more elements");

	std::vector<int>::iterator it_min = std::min_element(_span.begin(), _span.end());
	int min = *it_min;
	std::vector<int>::iterator it_max = std::max_element(_span.begin(), _span.end());
	int max = *it_max;

	size_t diff = static_cast<size_t>(max - min);

	// /*PRINT*/
	// std::cout	<< "\n" << max << "	-	" << min << "	=	" << diff << std::endl;
	// std::cout << "\nLongest span: ";
	
	return (diff);
}
