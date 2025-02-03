#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	delete j; // should not create a leak
	delete i;

	return (0);
}

// [ANIMAL ARRAY]

// int	main(void)
// {
// 	Animal* animals[10];

// 	for (int i = 0; i < 5; i++)
// 	{
// 		Dog* dog = new Dog();
// 		dog->pickBrain()->setIdea(0, "SQUIRREL!");
// 		animals[i] = dog;
// 	}
// 	for (int i = 5; i < 10; i++)
// 	{
// 		Cat *cat = new Cat();
// 		cat->pickBrain()->setIdea(0, "mice");
// 		animals[i] = cat;
// 	}
// 	for (int i = 0; i < 10; i++)
// 	{
// 		animals[i]->makeSound();
// 		std::cout << animals[i]->getType() << " is thinking of: " << animals[i]->pickBrain()->getIdea(0) << std::endl;
// 	}
// 	for (int i = 0; i < 10; i++)
// 	{
// 		delete animals[i];
// 	}
// 	return (0);
// }


// [DEEP COPY TEST]

// int	main(void) 
// {
// 	Dog mainDog;
// 	mainDog.pickBrain()->setIdea(0, "Chase ball!");
// 	std::cout << "mainDog brain idea: " << mainDog.pickBrain()->getIdea(0) << std::endl;
// 	{
// 		Dog tempDog = mainDog;
// 		std::cout << "tempDog brain idea: " << tempDog.pickBrain()->getIdea(0) << std::endl;

// 		tempDog.pickBrain()->setIdea(0, "Guard house!");
// 		std::cout << "tempDog brain updated idea: " << tempDog.pickBrain()->getIdea(0) << std::endl;
// 		std::cout << "mainDog brain idea remains: " << mainDog.pickBrain()->getIdea(0) << std::endl;
// 	}
// 	std::cout << "mainDog brain idea after tempDog died: " << mainDog.pickBrain()->getIdea(0) << std::endl;

// 	Cat mainCat;
// 	mainCat.pickBrain()->setIdea(0, "Lick paws");
// 	std::cout << "mainCat brain idea: " << mainCat.pickBrain()->getIdea(0) << std::endl;
// 	{
// 		Cat tempCat = mainCat;
// 		std::cout << "tempCat brain idea: " << tempCat.pickBrain()->getIdea(0) << std::endl;

// 		tempCat.pickBrain()->setIdea(0, "Nap in the sun");
// 		std::cout << "tempCat brain updated idea: " << tempCat.pickBrain()->getIdea(0) << std::endl;
// 		std::cout << "mainCat brain idea remains: " << mainCat.pickBrain()->getIdea(0) << std::endl;
// 	}
// 	std::cout << "mainCat brain idea after tempCat died: " << mainCat.pickBrain()->getIdea(0) << std::endl;

// 	return (0);
// }