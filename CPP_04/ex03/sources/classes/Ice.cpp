#include "../../headers/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice constructor" << std::endl;
}
Ice::Ice(const Ice& other) : AMateria("ice")
{
	// std::cout << "Ice copy constructor" << std::endl;
	*this = other;
}
Ice::~Ice()
{
	// std::cout << "Ice destructor" << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	// std::cout << "Ice copy assignment operator" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria* Ice::clone(void) const
{
	return(new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}