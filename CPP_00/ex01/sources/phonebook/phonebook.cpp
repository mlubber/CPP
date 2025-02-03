#include "../../headers/phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	contact_count = 0;
}

int	PhoneBook::getContactCount(void) const
{
	return (contact_count);
}

void PhoneBook::addContact(const Contact& new_contact)
{
	int	i;
	
	if (contact_count < 8) 
		contacts[contact_count++] = new_contact;
	else
	{
		i = 1;
		while (i < 8)
		{
			contacts[i - 1] = contacts[i];
			i++;
		}
		contacts[7] = new_contact;
	}
}

std::string	PhoneBook::truncate(const std::string& str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	PhoneBook::displayContacts() const
{
	int	i;
	
	i = 0;
	std::cout	<< "\n" << std::setw(10) << "#" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "\n"
 				<< "-------------------------------------------" << std::endl;
	if (contact_count > 0)
	{
		while (i < contact_count)
		{
			std::cout 	<< std::setw(10) << i + 1 << "|"
						<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
						<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
						<< std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
			i++;
		}
		std::cout << std::endl;
		return (1);
	}
	return (0);
}

void	PhoneBook::searchContact(int index) const
{
	if (index >= 0 && index < contact_count)
	{
		std::cout	<< "\n"
					<< "First Name: " << contacts[index].getFirstName() << "\n"
					<< "Last Name: " << contacts[index].getLastName() << "\n"
					<< "Nickname: " << contacts[index].getNickName() << "\n"
					<< "Phone Number: " << contacts[index].getNumber() << "\n"
					<< "Darkest Secret: " << contacts[index].getSecret() << "\n" << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}
