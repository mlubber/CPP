#include "../../headers/Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog born" << std::endl;
}

Dog::Dog(const Dog &other) : _brain(other._brain ? new Brain(*other._brain) : nullptr)
{
	_type = other._type;
	std::cout << "Dog cloned" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog died" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) 
{
	if (this != &other) 
	{
		this->_type = other._type;
		if (_brain) 
			delete _brain;
		this->_brain = other._brain ? new Brain(*other._brain) : nullptr;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "\"Woof!\"" << std::endl;
}

Brain	*Dog::pickBrain(void) const
{
	return (_brain);
}
