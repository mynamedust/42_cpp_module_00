#include "./Contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


class PhoneBook {
private:
	int count;
	int index;
	Contact contacts[8];

	void print();

	void headerPrint();

public:
	PhoneBook();

	void addContact();

	void searchContact();

	void exitPhoneBook();
};

#endif