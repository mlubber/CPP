#include "../../headers/Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{

}
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has perished." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
