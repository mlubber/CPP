#include "../headers/easyfind.hpp"

int main (void)
{
	try
	{
		std::vector<int> numbers;
		for (size_t i = 0; i < 5; ++i)
			numbers.push_back(i * 42);

		for (size_t i = 0; i < numbers.size(); i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;

		easyfind(numbers, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int> characters;

		for (size_t i = 0; i < 5; ++i)
			characters.push_back(i + 49);

		for (size_t i = 0; i < characters.size(); i++)
			std::cout << characters[i] << " ";
		std::cout << std::endl;

		easyfind(characters, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<char> characters;

		for (size_t i = 0; i < 5; ++i)
			characters.push_back(i + 49);

		for (size_t i = 0; i < characters.size(); i++)
			std::cout << characters[i] << " ";
		std::cout << std::endl;

		easyfind(characters, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}