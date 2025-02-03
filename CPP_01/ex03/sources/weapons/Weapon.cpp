#include "../../headers/Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(const std::string& initialtype)
{
	_type = initialtype;
}

Weapon::~Weapon()
{

}

const std::string&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(const std::string& newtype)
{
	_type = newtype;
}

