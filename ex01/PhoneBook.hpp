#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class PhoneBook {
private:
	int count;
	int index;
	Contact contacts[8];

	void printContactsTable();

	void headerPrint();

	void findIndexContact();

	void findIndexContact(std::string const &buff);
public:
	PhoneBook();

	void addContact();

	void searchContact();

	void exitPhoneBook();
};

#endif