#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Arr, typename Func>
void	iter(Arr* array, size_t length, Func function)
{
	if (!array)
		return ;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void printName(const T& element)
{
	std::cout << element;
}

void increment(int& num)
{
	num++;
}

void ft_increment(char& c)
{
	c = c + 42;
}
#endif