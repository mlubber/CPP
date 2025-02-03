#include "../../headers/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("CL4P-TP"), _hit_points(10), _energy_points(5), _attack_damage(5)
{
	std::cout << "ClapTrap default robot constructed" << std::endl;
}

// Overload constructor for a named Claptrap;
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap version: \"" << _name << "\" created" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap duplication process initiated" << std::endl;
	*this = other;
}

// Copy assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (_name.empty())
		std::cout << "ClapTrap " << other._name << "'s data is being copied"<< std::endl;
	else
		std::cout << "ClapTrap " << _name << "'s data is being overwritten by ClapTrap " << other._name << "'s" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is scrapped for parts" << std::endl;
}

// Member functions

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points == 0) 
	{
		std::cout	<< "ClapTrap " << _name
					<< " is all out of energy and unable to attack" << std::endl;
		return;
	}
	else if (_hit_points == 0) 
	{
		std::cout	<< "ClapTrap " << _name
					<< " has been reduced to scrap and can't attack" << std::endl;
		return;
	}
	_energy_points--;
	std::cout 	<< "ClapTrap " << _name
				<< " attacks " << target 
				<< " causing " << _attack_damage;
				if (_attack_damage == 1)
					std::cout << " point of damage!" << std::endl;
				else
					std::cout << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout	<< "ClapTrap " << _name
					<< " is already destroyed!" << std::endl;
		return;
	}
	_hit_points = (amount >= _hit_points) ? 0 : (_hit_points - amount);
    std::cout	<< "ClapTrap " << _name
				<< " takes " << amount;
	if (amount == 1)
		std::cout << " point of damage";
	else
		std::cout << " points of damage";
	if (_hit_points == 0)
		std::cout << " and has been reduced to scrap" << std::endl;
	else
   		std::cout << "! Remaining hit points: " << _hit_points << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout	<< "ClapTrap " << _name
					<< " tries to make repairs, "
					<< "but internal structural damage is critical" << std::endl;
		return;
	}
	_energy_points--;
	_hit_points += amount;
	std::cout	<< "ClapTrap " << _name
				<< " makes repairs, recovering " << amount
            	<< " hit points. Current hit points: " << _hit_points << std::endl;
}

std::string ClapTrap::getName(void)
{
	return (_name);
}