#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	count = 0;
	index = 0;
}

void PhoneBook::addContact() {
	Contact contact;
	int idx;

	if (count < 8)
		idx = count++;
	else {
		if (index > 7)
			index = 0;
		idx = index;
	}
	if (!contact.fillContact(idx)) {
		std::cout << "Creating failed. Contact can’t have empty fields.";
		return;
	}
	contacts[index++] = contact;
}

void PhoneBook::headerPrint() {
	std::cout << std::right << std::setw(10) << "INDEX" << '|';
	std::cout << std::right << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::right << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::right << std::setw(10) << "NICKNAME" << '|' << std::endl;
}

void PhoneBook::print() {
	if (count == 0) {
		std::cout << "Phone Book is empty now\n";
		return;
	}
	headerPrint();
	for (int i = 0; i < count; i++) {
		contacts[i].tablePrint();
	}
}

void PhoneBook::searchContact() {
	print();
}

#include "PhoneBook.hpp"
