#include "../../headers/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "ScalarConverter copy constructor" << std::endl;
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "ScalarConverter copy assignment operator" << std::endl;
	(void)other;
	return (*this);
}

void	ScalarConverter::convert(const std::string& str)
{
	std::cout << "Converter:" << std::endl;
	size_t len = str.length();
	e_type type = getType(str, len);
	
	switch (type)
	{
		case INVALID:
			std::cout << "Invalid input" << std::endl;
			break;
		case EDGE:
			printEdge(str);
			break;
		case CHAR:
			convertChar(str, len);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
	}
}


