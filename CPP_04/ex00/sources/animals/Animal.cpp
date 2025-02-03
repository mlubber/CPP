#include "../../headers/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal spawned" << std::endl;
}
Animal::Animal(const Animal &other)
{
	*this = other;
}
Animal::~Animal()
{
	std::cout << "Animal cremated" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "\"Generic animal sound!\"" << std::endl;
}