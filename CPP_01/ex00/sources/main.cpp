#include "../headers/Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie *heapZombie = newZombie("HeapHank");
	heapZombie->announce();
	
	delete heapZombie;

	randomChump("StackSteve");

	return (0);
}
