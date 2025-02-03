#include "../../headers/Replace.h"

int	error_check(std::string& filename, std::string& str1, std::ifstream& infile, int out)
{
	if (str1.empty()) 
	{
		std::cerr << "Error: The string to replace (str1) cannot be empty." << std::endl;
		return (1);
	}
	if (!infile) 
	{
		std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
		return (1);
	}
	if (out == 1)
	{
		std::cerr << "Error: Could not create file " << filename << ".replace for writing." << std::endl;
		return (1);
	}
	return (0);
}

void	replace(std::ofstream& outfile, const std::string& line, const std::string& str1, const std::string& str2)
{
	size_t	pos = 0;
	size_t	start = 0;

	while ((pos = line.find(str1, start)) != std::string::npos)
	{
		outfile << line.substr(start, pos - start) << str2;
		start = pos + str1.length();
	}
	outfile << line.substr(start) << std::endl;
}
