#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	employee("Steve", 5);
		Form 		order("paper", 4, 1);

		std::cout << employee << std::endl;
		std::cout << order << std::endl;

		employee.signForm(order);
		employee.incrementGrade();
		std::cout << employee << std::endl;
		employee.signForm(order);
		std::cout << order << std::endl;
		employee.signForm(order);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}