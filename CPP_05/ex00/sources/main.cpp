#include "../headers/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat employee01("steve", 2);
		std::cout << employee01 << std::endl;

		employee01.incrementGrade();
		std::cout << employee01 << std::endl;

		employee01.incrementGrade();
		std::cout << employee01 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat employee02("alice", 149);
		std::cout << employee02 << std::endl;

		employee02.decrementGrade();
		std::cout << employee02 << std::endl;

		employee02.decrementGrade();
		std::cout << employee02 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}