#include "../../headers/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat born" << std::endl;
}
Cat::Cat(const Cat &other)
{
	*this = other;
}
Cat::~Cat()
{
	std::cout << "Cat died" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "\"Meow!\"" << std::endl;
}
