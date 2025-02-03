#include "../../headers/DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("CL4P-TP_clap_name"), ScavTrap(), FragTrap(), _name("CL4P-TP")
{
	std::cout << "DiamTrap default mineral mined" << std::endl;
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}
DiamondTrap::DiamondTrap(const std::string &name)
	: ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamTrap mineral \"" << name << "\" mined" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamTrap splicing operation started" << std::endl;
	*this = other;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamTrap mineral " << getName() << " smelted" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other) 
	{
		std::cout << "DiamTrap " << other.getName() << " is assigned to DiamTrap " << getName() << std::endl;
		ClapTrap::operator=(other);
		_name = other._name;
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamTrap I am \"" << _name << "\" and my ClapTrap name is: \"" << ClapTrap::_name << "\"" << std::endl;
}