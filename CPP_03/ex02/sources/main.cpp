#include "../headers/FragTrap.hpp"

int main(void)
{
	FragTrap	frag;
	FragTrap	decepticon("Megatron");
	FragTrap	autobot("Optimus");
	FragTrap	clone(decepticon);
	
	std::cout << std::endl;

	autobot.attack(decepticon.getName());
	decepticon.takeDamage(30);
	decepticon.beRepaired(30);
	autobot.attack(decepticon.getName());
	autobot.attack(decepticon.getName());
	autobot.attack(decepticon.getName());
	autobot.attack(decepticon.getName());
	decepticon.takeDamage(120);
	autobot.attack(decepticon.getName());
	decepticon.takeDamage(30);
	decepticon.attack(autobot.getName());
	decepticon.beRepaired(100);
	decepticon.highFivesGuys();
	autobot.attack(clone.getName());
	clone.takeDamage(30);
	clone.beRepaired(30);
	autobot.highFivesGuys();
	autobot.setEnergyPoints(1);
	autobot.attack("fred");
	autobot.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
