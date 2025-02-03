#include "../headers/ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap;
	ClapTrap	red("Robert");
	ClapTrap	blue("Brian");
	ClapTrap	green("Greg");
	ClapTrap	yellow(blue);

	red = clap;
	std::cout << std::endl;

	red.attack(blue.getName());
	blue.takeDamage(5);
	blue.beRepaired(5);
	red.attack(blue.getName());
	blue.takeDamage(5);
	red.attack(blue.getName());
	blue.takeDamage(5);
	red.attack(blue.getName());
	blue.takeDamage(5);
	blue.attack(red.getName());
	blue.beRepaired(10);
	red.attack(green.getName());
	green.takeDamage(5);
	green.beRepaired(5);

	std::cout << std::endl;

	return (0);
}
