#include "../headers/Point.hpp"

int	main(void)
{
	{
		Point a(0, 0);
		Point b(5, 0);
		Point c(0, 5);

		Point d(1, 1);
		Point e(6, 6);
		Point f(0, 0);
		Point g(0, 1);
		
		std::cout << "Point inside? " << bsp(a, b, c, d) << std::endl;
		std::cout << "Point inside? " << bsp(a, b, c, e) << std::endl;
		std::cout << "Point inside? " << bsp(a, b, c, f) << std::endl;
		std::cout << "Point inside? " << bsp(a, b, c, g) << std::endl;
	}
	{
		Point a(0, 0);
		Point b(5.5, 0);
		Point c(0, 5.5);

		Point d(2.2, 2.2);
		Point e(6.6, 6.6);
		Point f(0, 0);
		Point g(0, 2.2);
		
		std::cout << "Point inside? " << bsp(a, b, c, d) << std::endl;
		std::cout << "Point inside? " << bsp(a, b, c, e) << std::endl;
		std::cout << "Point inside? " << bsp(a, b, c, f) << std::endl;
		std::cout << "Point inside? " << bsp(a, b, c, g) << std::endl;
	}

	return (0);
}
