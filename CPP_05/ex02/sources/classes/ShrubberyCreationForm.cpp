#include "../../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("SCF", target, 145, 137)
{
	std::cout << "SCF default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << "SCF copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "SCF destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "SCF copy assignment operator" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream file(getTarget() + "_shrubbery");
	if (file.is_open())
	{
		file << "              /\\\n"
				"             /||\\     /|\\\n"
				"     /\\      /||\\     /|\\ /|\\\n"
				"    /||\\ /\\ //||\\\\   //|\\\\/|\\\n"
				"/|\\ /||\\/||\\//||\\\\   //|\\//|\\\\ /|\\\n"
				"/|\\//||\\/||\\//||\\\\\\ ///|\\//|\\\\ /|\\ /|\\\n"
				"/|\\//||//||///||\\\\\\ ///|///|\\\\//|\\\\/|\\\n"
				"/|///||//|////||\\\\\\////|///|\\\\//|\\//|\\\n"
				"_|___||__||___||_______|___|____|___|_\n";
				
		file.close();
		std::cout << "[Some trees were planted at " << getTarget() << "]" << std::endl;
	}
	else
		std::cerr << "Error: Unable to create shrubbery file." << std::endl;
}