#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat employee01("CEO", 1);
	Bureaucrat employee02("president", 6);
	Bureaucrat employee03("boss", 46);
	Bureaucrat employee04("manager", 138);
	Bureaucrat employee05("intern", 150);

	ShrubberyCreationForm SCF("home");
	RobotomyRequestForm RRF("Bob");
	PresidentialPardonForm PPF("Alice");

	std::cout << std::endl;
	std::cout << employee01 << std::endl;
	std::cout << employee02 << std::endl;
	std::cout << employee03 << std::endl;
	std::cout << employee04 << std::endl;
	std::cout << employee05 << std::endl;
	std::cout << std::endl;
	std::cout << SCF << std::endl;
	std::cout << RRF << std::endl;
	std::cout << PPF << std::endl;
	std::cout << std::endl;
	employee05.signForm(SCF);
	employee04.signForm(SCF);
	employee04.executeForm(SCF);
	employee03.executeForm(SCF);
	std::cout << std::endl;
	employee05.signForm(RRF);
	employee04.signForm(RRF);
	employee03.signForm(RRF);
	employee03.executeForm(RRF);
	employee02.executeForm(RRF);
	std::cout << std::endl;
	employee05.executeForm(PPF);
	employee01.signForm(PPF);
	employee05.executeForm(PPF);
	employee02.executeForm(PPF);
	employee02.incrementGrade();
	employee02.executeForm(PPF);
	std::cout << std::endl;
	return (0);
}