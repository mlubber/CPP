#include "../headers/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::map<std::string, double> database;
	std::ifstream infile(argv[1]);
	if (readData(database) == 1 || argc != 2 || !infile)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return (1);
	}

	std::string line;
	std::getline(infile, line);

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string date, rate;
		if (getline(iss, date, '|') && getline(iss, rate) && validDate(date))
		{
			if (std::stod(rate) < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (std::stod(rate) > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cout << date << "=>" << rate << " = " << std::stod(rate) * findRate(date, database) << std::endl;
		}
		else
			std::cerr << "Error: bad input => " << date << std::endl;
	}
	infile.close();
	return (0);
}