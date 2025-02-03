#include "../../headers/Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name) : _name(name)
{

}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has perished." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": MooaaaR BraiiiiiiinnnzzzZ!" << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
