#include "../headers/Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*horde;
	int		zombie_nbr = 5;

	horde = zombieHorde(zombie_nbr, "HordeHorace");

	for (int i = 0; i < zombie_nbr; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
