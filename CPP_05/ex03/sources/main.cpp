#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	employee01("CEO", 1);
		Intern		intern01;
		AForm* 		SCF;
		AForm*		RRF;
		AForm*		PPF;
		AForm*		invalid;

		std::cout << std::endl;
		SCF = intern01.makeForm("shrubbery creation", "home");
		std::cout << *SCF << std::endl;
		employee01.executeForm(*SCF);
		employee01.signForm(*SCF);
		employee01.executeForm(*SCF);
		delete SCF;
		std::cout << std::endl;
		RRF = intern01.makeForm("robotomy request", "Bender");
		std::cout << *RRF << std::endl;
		employee01.signForm(*RRF);
		employee01.executeForm(*RRF);
		delete RRF;
		std::cout << std::endl;
		PPF = intern01.makeForm("presidential pardon", "Arthur");
		std::cout << *PPF << std::endl;
		employee01.signForm(*PPF);
		employee01.executeForm(*PPF);
		delete PPF;
		invalid = intern01.makeForm("invalid form", "street");
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return (0);
}