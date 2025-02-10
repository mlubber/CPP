#include "../../headers/ScalarConverter.hpp"

static int typeEdge(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf"
		||	str == "+inff" || str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

static int	typeChar(const std::string& str, size_t len)
{
	if (len == 1 && !isdigit(str[0]))
		return (1);
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return (1);
	return (0);
}

static int typeInt(const std::string& str, size_t len)
{
	bool	sign = false;
	int		i = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		sign = true;
		i++;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && !sign && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
	
}

static int	typeFloat(const std::string& str, size_t len, size_t dot)
{
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return (0);
		if (str[i] == 'f' && i != len - 1)
			return (0);
	}
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return (0);
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return (0);
	}
	return (1);
}

e_type getType(const std::string& str, size_t len)
{
	size_t dot = str.find('.');
	size_t f = str.find('f');

	if (dot == std::string::npos)
	{
		if (typeEdge(str))
			return EDGE;
		if (typeChar(str, len))
			return CHAR;
		if (typeInt(str, len))
			return INT;
	}
	if (f != std::string::npos && dot != std::string::npos)
	{
		if (typeFloat(str, len, dot))
			return FLOAT;
	}
	else if (f == std::string::npos && dot != std::string::npos)
		return DOUBLE;
	return (INVALID);
}