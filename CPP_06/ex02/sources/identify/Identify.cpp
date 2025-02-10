#include "../../headers/Identify.hpp"

Base*	generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
		return (new A());
	if (random == 1) 
		return (new B());
	if (random == 2) 
		return (new C());
	return (nullptr);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} 
	catch (std::bad_cast& e) {}

	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} 
	catch (std::bad_cast& e) {}

	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} 
	catch (std::bad_cast& e) {}
	std::cout << "Unknown" << std::endl;
}
