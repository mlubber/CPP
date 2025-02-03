#include "../headers/ScavTrap.hpp"

int main(void)
{
	ScavTrap	scav;
	ScavTrap	android("Andy");
	ScavTrap	robot("Ronny");
	ScavTrap	copy(robot);

	std::cout << std::endl;

	scav.guardGate();
	android.attack(copy.getName());
	copy.takeDamage(20);
	copy.beRepaired(20);
	android.attack(copy.getName());
	android.attack(copy.getName());
	android.attack(copy.getName());
	android.attack(copy.getName());
	android.attack(copy.getName());
	copy.takeDamage(100);
	android.attack(copy.getName());
	copy.takeDamage(20);
	copy.attack(android.getName());
	copy.beRepaired(100);
	android.attack(scav.getName());
	scav.takeDamage(20);
	scav.beRepaired(20);
	scav.setEnergyPoints(0);
	scav.attack(copy.getName());

	std::cout << std::endl;

	return (0);
}
