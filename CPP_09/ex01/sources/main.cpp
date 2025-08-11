#include "../headers/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: RPN Needs a single string argument" << std::endl;
		return (1);
	}
	try
	{
		std::cout << calculate(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}