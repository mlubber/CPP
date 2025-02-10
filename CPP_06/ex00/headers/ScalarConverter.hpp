#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <limits>
# include <cmath>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT -std::numeric_limits<float>::max()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

enum	e_type
{
	EDGE = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class ScalarConverter
{
	public:

		static void			convert(const std::string& str);

	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& other);

};

e_type 		getType(const std::string& str, size_t len);
void		printEdge(const std::string& str);
void		convertChar(const std::string& str, size_t& len);
void		convertInt(const std::string& str);
void		convertFloat(const std::string& str);
void		convertDouble(const std::string& str);

#endif