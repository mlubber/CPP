#include "../../headers/Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat born" << std::endl;
}
Cat::Cat(const Cat &other) : _brain(other._brain ? new Brain(*other._brain) : nullptr)
{
	_type = other._type;
	std::cout << "Cat cloned" << std::endl;
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat died" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
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

void	Cat::makeSound(void) const
{
	std::cout << "\"Meow!\"" << std::endl;
}

Brain	*Cat::pickBrain(void) const
{
	return (_brain);
}
