#include "../../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RRF", target, 72, 45)
{
	std::cout << "RRF default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	std::cout << "RRF copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RRF destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RRF copy assignment operator" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void	RobotomyRequestForm::action() const
{
	std::cout << "*Drilling noises*" << std::endl;
	srand(time(0));
	if (rand() % 2 == 0) 
		std::cout << "[" << getTarget() << " has been robotomized successfully!]" << std::endl;
	else
		std::cout << "[Robotomy of " << getTarget() << " failed]" << std::endl;
}