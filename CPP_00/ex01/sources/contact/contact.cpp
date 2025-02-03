#include "../../headers/contact.hpp"

void Contact::setDetails(const std::string& first, const std::string& last, const std::string& nick, const std::string& nbr, const std::string& secret)
{
	first_name = first;
    last_name = last;
	nickname = nick;
	phone_nbr = nbr;
	dark_secret = secret;
}

std::string Contact::getFirstName() const
{
	return (first_name);
}

std::string Contact::getLastName() const
{
	return (last_name);
}

std::string Contact::getNickName() const
{
	return (nickname);
}

std::string Contact::getNumber() const
{
	return (phone_nbr);
}

std::string Contact::getSecret() const
{
	return (dark_secret);
}