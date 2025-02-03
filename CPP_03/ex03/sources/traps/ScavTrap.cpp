#include "../../headers/ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default robot assembled" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

// Constructor for a named ScavTrap;
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap robot \"" << name << "\" assembled" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap duplication process initiated" << std::endl;
	*this = other;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap robot " << _name << " deconstructed" << std::endl;
}

// Copy assignment operator overload
ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
	if (this != &other) 
	{
		std::cout << "ScavTrap " << other.getName() << " is assigned to ScavTrap " << getName() << std::endl;
		ClapTrap::operator=(other);
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void		ScavTrap::attack(const std::string& target)
{
	if (_energy_points == 0) 
	{
		std::cout	<< "ScavTrap " << _name
					<< "'s battery is depleated and unable to attack" << std::endl;
		return;
	}
	else if (_hit_points == 0) 
	{
		std::cout	<< "ScavTrap " << _name
					<< " has been pulverised and can't attack" << std::endl;
		return;
	}
	_energy_points--;
	std::cout 	<< "ScavTrap " << _name
				<< " attacks " << target 
				<< " inflicting " << _attack_damage;
				if (_attack_damage == 1)
					std::cout << " point of damage!" << std::endl;
				else
					std::cout << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode" << std::endl;
}