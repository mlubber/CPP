#include "../headers/iter.hpp"

int	main(void)
{
	{
		int		arr[] = {1, 2, 3, 4, 5};
		size_t	size = sizeof(arr) / sizeof(arr[0]);

		::iter(arr, size, printElement<int>);
		std::cout << std::endl;
		::iter(arr, size, increment);
		::iter(arr, size, printElement<int>);
		std::cout << std::endl;
	}
	{
		std::string	arr[] = {"Hello", "World", "This", "Is", "Me"};
		size_t		size = sizeof(arr) / sizeof(arr[0]);

		::iter(arr, size, printElement<std::string>);
		std::cout << std::endl;
	}
	{
		char	arr[] = {'#', '?', '9', '>', ';', 'B'};
		size_t	size = sizeof(arr) / sizeof(arr[0]);

		::iter(arr, size, ft_increment);
		::iter(arr, size, printName<char>);
		std::cout << std::endl;
	}
	return (0);
}
