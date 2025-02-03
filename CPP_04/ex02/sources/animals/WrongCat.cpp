#include "../../headers/WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Wrong cat born" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
}
WrongCat::~WrongCat()
{
	std::cout << "Wrong cat died" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "\"WrongMeow!\"" << std::endl;
}
