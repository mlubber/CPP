#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

int		readData(std::map<std::string, double>& data);
double	findRate(std::string date, std::map<std::string, double>& database);
bool	validDate(std::string date);

