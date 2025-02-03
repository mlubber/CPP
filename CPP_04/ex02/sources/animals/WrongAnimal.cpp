#include "../../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Wrong animal spawned" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal cremated" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "\"Generic wrong animal sound!\"" << std::endl;
}