#include "../../headers/BitcoinExchange.hpp"

int	readData(std::map<std::string, double>& database)
{
	std::ifstream infile("data.csv");
	if (!infile)
		return (1);

	std::string line;
	std::getline(infile, line);

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string date, rate;
		if (getline(iss, date, ',') && getline(iss, rate))
		{
			double exchange_rate = std::stod(rate);
			database[date] = exchange_rate;
		}
	}
	infile.close();
	return (0);
}

double	findRate(std::string date, std::map<std::string, double>& database)
{
	std::map<std::string, double>::iterator it = database.lower_bound(date);
	if (it != database.end() && it->first == date)
		return (it->second);
	else
	{
		if (it == database.begin())
		{
			std::cout << "Error: date not available in database." << std::endl;
			return (1);
		}
		else
		{
			--it;
			return (it->second);
		}
	}
	return (1);
}

std::string tmToString(const std::tm& tm, const char* format = "%Y-%m-%d")
{
	std::ostringstream oss;
	oss << std::put_time(&tm, format);
	return (oss.str());
}

time_t	makeTime(std::string date)
{
	if (date.length() != 10)
		return (-1);
	
	std::tm tm = {};
	std::istringstream iss(date);

	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (iss.fail())
		return (-1);
	
	int parsed_year = tm.tm_year;
	int parsed_month = tm.tm_mon;
	int parsed_day = tm.tm_mday;
	
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	tm.tm_isdst = -1;
	time_t time = std::mktime(&tm);
	if (time == -1)
		return (-1);

	if (tm.tm_year != parsed_year ||
		tm.tm_mon != parsed_month ||
		tm.tm_mday != parsed_day)
		return (-1);

	return (time);
}

bool	validDate(std::string date)
{
	time_t now = std::time(0);
	std::tm* now_tm = std::localtime(&now);

	time_t time = makeTime(date);	// Given date
	time_t min_date = makeTime("2009-01-01");	// BTC start
	time_t today = makeTime(tmToString(*now_tm)); // Today

	if (time == -1 || min_date == -1 || today == -1)
		return (0);

	return (time >= min_date && time <= today);
}


