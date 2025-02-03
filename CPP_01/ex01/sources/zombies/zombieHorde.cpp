#include "../../headers/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::ostringstream append;
		append << name << i;
		horde[i].setName(append.str());
	}
	return (horde);
}