#include "../../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PPF", target, 25, 5)
{
	std::cout << "PPF default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	std::cout << "PPF copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PPF destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PPF copy assignment operator" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void	PresidentialPardonForm::action() const
{
	std::cout << "[" << getTarget() << " has been pardoned by Zaphod Beeblebrox]" << std::endl;
}