#ifndef REPLACE_H
# define REPLACE_H

# include <string>
# include <fstream>
# include <iostream>

int		error_check(std::string& filename, std::string& str1, std::ifstream& infile, int out);
void	replace(std::ofstream& outfile, const std::string& line, const std::string& str1, const std::string& str2);

#endif