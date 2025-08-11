#include "../headers/Span.hpp"

int main (void)
{
	std::srand(std::time(0));
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout	<< sp.shortestSpan() << "\n"
					<< sp.longestSpan() << "\n"
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		int size = 10000;
		Span sp = Span(size);

		for (int i = 0; i < size; ++i)
			sp.addNumber(std::rand());

		std::cout	<< sp.shortestSpan() << "\n"
					<< sp.longestSpan() << "\n"
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		int size = 10000;
		Span sp = Span(size);

		std::vector<int> numbers;
		numbers.reserve(size);

		for (int i = 0; i < size; ++i)
			numbers.push_back(std::rand());

		sp.addRange(numbers.begin(), numbers.end());

		std::cout	<< sp.shortestSpan() << "\n"
					<< sp.longestSpan() << "\n"
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}