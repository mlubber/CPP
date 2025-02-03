#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define PHONEBOOK "       _                      _                 _    \n _ __ | |__   ___  _ __   ___| |__   ___   ___ | | __\n| '_ \\| '_ \\ / _ \\| '_ \\ / _ \\ '_ \\ / _ \\ / _ \\| |/ /\n| |_) | | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n| .__/|_| |_|\\___/|_| |_|\\___|_.__/ \\___/ \\___/|_|\\_\\\n|_|                                                  \n"

# include "contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[8];
		int		contact_count;

	public:
		PhoneBook();
		void		addContact(const Contact& new_contact);
		std::string	truncate(const std::string& str) const;
		int			displayContacts() const;
		void		searchContact(int index) const;
		int			getContactCount(void) const;
};

#endif