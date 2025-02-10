#include "../../headers/ScalarConverter.hpp"

void	printEdge(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: nanf\n"
					<< "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: +inff\n"
					<< "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: -inff\n"
					<< "double: -inf" << std::endl;
	}
}

void	convertChar(const std::string& str, size_t& len)
{
	char	c;

	if (len == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
	{
		std::cout	<< "'" << c << "'"
					<< "\nint: " << static_cast<int>(c)
					<< "\nfloat: " << static_cast<float>(c) << ".0f"
					<< "\ndouble: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

void	convertInt(const std::string& str)
{
	long i = std::stol(str);

	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayble" << std::endl;
	}
	std::cout << "int: ";
	if (i < MIN_INT || i > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(i) << std::endl;
	std::cout	<< "float: " << static_cast<float>(i) << ".0f\n"
				<< "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	convertFloat(const std::string& str)
{
	float	f = std::stof(str);
	bool	round = std::fabs(f - static_cast<int>(f)) < 0.00005;

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(f))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << (round ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(f) << (round ? ".0" : "") << std::endl;
}

void	convertDouble(const std::string& str)
{
	double	d = std::stod(str);
	bool	round = std::fabs(static_cast<float>(d) - static_cast<int>(d)) < 0.00005;

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d < MIN_FLOAT || d > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (round ? ".0f" : "f") << std::endl;
	std::cout << "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}
