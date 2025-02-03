#include "../headers/Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <log_level>\n";
		return (1);
	}

	Harl karen;

	karen.filter(argv[1]);
	return (0);
}
