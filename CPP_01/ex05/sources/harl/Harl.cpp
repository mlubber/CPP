#include "../../headers/Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug(void)
{
	std::cout	<< "\n[ DEBUG ]\n" 
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger.\n" 
				<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "\n[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn't put enough bacon in my burger!\n"
				<< "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "\n[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I've been coming for years "
				<< "whereas you started working here since last month." << std::endl;

}

void	Harl::error(void)
{
	std::cout	<< "\n[ ERROR ]\n"
				<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*HarlFunc)(void);
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlFunc functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}