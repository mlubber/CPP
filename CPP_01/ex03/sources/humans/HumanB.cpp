#include "../../headers/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{

}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	_weapon = &new_weapon;
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with!" << std::endl;
}

