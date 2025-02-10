#include "../headers/Identify.hpp"

int	main(void)
{
	std::srand(std::time(0));

	for (int i = 0; i < 5; i++)
	{
		Base*	basePtr = generate();
		std::cout << "Pointer-based identification: " << std::endl;
		identify(basePtr);
		std::cout << "Reference-based identification: " << std::endl;
		identify(*basePtr);
		std::cout << "-------------------------------" << std::endl;
		delete basePtr;
	}
	return (0);
}