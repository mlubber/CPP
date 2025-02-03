#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact 
{
	private:
		std::string last_name;
		std::string first_name;
		std::string	nickname;
		std::string	phone_nbr;
		std::string	dark_secret;

	public:
		Contact() {}
		void setDetails(const std::string& last, const std::string& first, const std::string& nick, const std::string& nbr, const std::string& secret);
		std::string getLastName() const;
		std::string getFirstName() const;
		std::string getNickName() const;
		std::string getNumber() const;
		std::string getSecret() const;
};

#endif