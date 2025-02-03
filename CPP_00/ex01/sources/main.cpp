#include "../headers/phonebook.hpp"
#include "../headers/contact.hpp"
#include <iostream>
#include <limits>

void	search(PhoneBook phonebook)
{
	int index;

	if (phonebook.displayContacts() == 1)
	{
		std::cout << "Enter index number to view contact details: ";
		while (true) {
			std::cin >> index;
			if (std::cin.fail() || index < 1 || index > phonebook.getContactCount())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a valid index number: ";
			} 
			else 
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}
		phonebook.searchContact(index - 1);
	}
	else
		std::cout << "\nPhonebook is empty.\n" << std::endl;
}

std::string	nbr_check(std::string nbr)
{
	bool	valid;

	while (1)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, nbr);
		valid = true;
		for (char c : nbr)
		{
			if (!std::isdigit(c))
			{
				valid = false;
				break;
			}
		}
		if (valid && !nbr.empty())
			break;
		std::cout << "Please enter a valid ";
	}
	return (nbr);
}

std::string	input_check(const char *str, std::string input)
{
	while (1)
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Please enter a valid ";
	}
	return (input);
}

Contact	add(Contact new_contact)
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	nbr;
	std::string	secret;
	
	first = input_check("First Name: ", first);
	last = input_check("Last Name: ", last);
	nick = input_check("Nickname: ", nick);
	nbr = nbr_check(nbr);
	secret = input_check("Darkest Secret: ", secret);
	new_contact.setDetails(first, last, nick, nbr, secret);
	return (new_contact);
}

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	command;

	std::cout << PHONEBOOK << std::endl;
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
			phonebook.addContact(add(contact));
		else if (command == "SEARCH" || command == "search")
			search(phonebook);
		else if (command == "EXIT" || command == "exit")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
