#include "../../headers/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure constructor" << std::endl;
}
Cure::Cure(const Cure& other) : AMateria("cure")
{
	// std::cout << "Cure copy constructor" << std::endl;
	*this = other;
}
Cure::~Cure()
{
	// std::cout << "Cure destructor" << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	// std::cout << "Cure copy assignment operator" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria* Cure::clone(void) const
{
	return(new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}