#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout	<< "\nMemory address of the string variable:	" << &str
				<< "\nMemory address held by stringPTR:	" << stringPTR
				<< "\nMemory address held by stringREF:	" << &stringREF

				<< "\n\nValue of the string variable:	" << str
				<< "\nValue pointed to by stringPTR:	" << *stringPTR
				<< "\nValue pointed to by stringREF:	" << stringREF << std::endl;
	return (0);
}
