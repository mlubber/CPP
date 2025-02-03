#include "../headers/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond;
	DiamondTrap red("Ruby");
	DiamondTrap	blue("Sapphire");
	DiamondTrap fake(red);

	std::cout << std::endl;

	diamond.guardGate();
	diamond.whoAmI();
	red.whoAmI();
	blue.whoAmI();
	fake.whoAmI();
	red.attack(blue.getName());
	blue.takeDamage(30);
	blue.beRepaired(10);
	red.attack(blue.getName());
	red.attack(blue.getName());
	red.attack(blue.getName());
	blue.takeDamage(90);
	red.attack(blue.getName());
	blue.takeDamage(30);
	blue.beRepaired(10);
	blue.attack(red.getName());
	blue.highFivesGuys();
	red.attack(diamond.getName());
	diamond.takeDamage(30);
	diamond.beRepaired(30);
	red.highFivesGuys();
	red.setEnergyPoints(0);
	red.attack(diamond.getName());
	red.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
