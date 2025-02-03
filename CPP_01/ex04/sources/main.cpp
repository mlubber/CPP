#include "../headers/Replace.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <string_to_replace> <replacement_string>" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	str1 = argv[2];
	std::string	str2 = argv[3];
	std::ifstream infile(filename);
	if (error_check(filename, str1, infile, 0) == 1)
		return (1);

	std::ofstream outfile(filename + ".replace");
	if (!outfile)
		return (error_check(filename, str1, infile, 1));

	std::string line;
	while (std::getline(infile, line))
		replace(outfile, line, str1, str2);

	infile.close();
	outfile.close();
	return (0);
}
