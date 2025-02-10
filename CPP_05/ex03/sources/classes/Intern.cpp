#include "../../headers/Intern.hpp"
# include "../../headers/ShrubberyCreationForm.hpp"
# include "../../headers/RobotomyRequestForm.hpp"
# include "../../headers/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor" << std::endl;
	(void)other;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	std::cout << "Intern copy assignment operator" << std::endl;
	(void)other;
	return (*this);
}

AForm* Intern::makeForm(const std::string& form_name, const std::string& target)
{
	std::string forms[] =
	{
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"
	};

	AForm* (*formCreators[])(const std::string&) =
	{
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (form_name == forms[i]) 
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (formCreators[i](target));
		}
	}
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found!");
}

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}