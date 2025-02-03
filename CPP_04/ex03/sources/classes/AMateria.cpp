#include "../../headers/AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "Materia constructed" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	// std::cout << "Materia constructed and assigned type: " << type << std::endl;
}
AMateria::AMateria(const AMateria& other)
{
	*this = other;
	// std::cout << "Materia copied" << std::endl;
}
AMateria::~AMateria()
{
	// std::cout << "Materia destructed" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (_type);
}