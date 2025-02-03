#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	return (0);
}

// int	main(void)
// {
// 	const Animal *meta;
// 	const Animal *c;
// 	const Animal *d;

// 	meta = new Animal();

// 	std::cout << "Of type: " << meta->getType() << std::endl;
// 	meta->makeSound();

// 	delete meta;
// 	std::cout << std::endl;

// 	c = new Cat();

// 	std::cout << "Of type: " << c->getType() << std::endl;
// 	c->makeSound();

// 	delete c;
// 	std::cout << std::endl;

// 	d = new Dog();

// 	std::cout << "Of type: " << d->getType() << std::endl;
// 	d->makeSound();

// 	delete d;
// 	std::cout << std::endl;

// 	const WrongAnimal	*wrongMeta;
// 	const WrongCat		*wrongCat;

// 	wrongMeta = new WrongAnimal();

// 	std::cout << "Of type: " << wrongMeta->getType() << std::endl;
// 	wrongMeta->makeSound();

// 	delete wrongMeta;
// 	std::cout << std::endl;

// 	wrongCat = new WrongCat();

// 	std::cout << "Of type: " << wrongCat->getType() << std::endl;
// 	wrongCat->makeSound();

// 	delete wrongCat;
// 	return (0);
// }