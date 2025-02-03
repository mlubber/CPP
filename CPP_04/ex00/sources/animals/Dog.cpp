#include "../../headers/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog born" << std::endl;
}
Dog::Dog(const Dog &other)
{
	*this = other;
}
Dog::~Dog()
{
	std::cout << "Dog died" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\"Woof!\"" << std::endl;
}
