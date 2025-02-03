#include "../../headers/FragTrap.hpp"

// Default constructer
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default transformer ready" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

// Constructor for a named FragTrap;
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap transformer \"" << name << "\" ready" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap cloning procedure commenced" << std::endl;
	*this = other;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap transformer " << _name << " decommissioned" << std::endl;
}

// Copy assignment operator overload
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		std::cout << "FragTrap " << other.getName() << " is assigned to FragTrap " << getName() << std::endl;
		ClapTrap::operator=(other);
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (_energy_points == 0) 
	{
		std::cout	<< "FragTrap " << _name
					<< " is out of power and unable to emote" << std::endl;
		return;
	}
	else if (_hit_points == 0) 
	{
		std::cout	<< "FragTrap " << _name
					<< " has been decimated and can't emote" << std::endl;
		return;
	}
	_energy_points--;
	std::cout 	<< "FragTrap " << _name
				<< " high fives everyone" << std::endl;
}