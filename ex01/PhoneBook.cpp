#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	count = 0;
	index = 0;
}

void PhoneBook::addContact() {
	Contact contact;
	int idx;

	if (!contact.fillContact()) {
		std::cout << "Creating failed. Contact can’t have empty fields." << std::endl;
		return;
	}
	if (count < 8)
		idx = count++;
	else {
		if (index > 7)
			index = 0;
		idx = index;
	}
	contact.setIndex(idx);
	contacts[index++] = contact;
}

void PhoneBook::headerPrint() {
	std::cout << std::right << std::setw(10) << "INDEX" << '|';
	std::cout << std::right << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::right << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::right << std::setw(10) << "NICKNAME" << '|' << std::endl;
}

void PhoneBook::printContactsTable() {
	headerPrint();
	for (int i = 0; i < count; i++) {
		contacts[i].tablePrint();
	}
}

void PhoneBook::findIndexContact(std::string const & buff) {
	int idx;
	int i = 0;

	while (buff[i]) {
		if (!isdigit(buff[i]))
			break;
		i++;
	}
	idx = atoi(buff.c_str());
	if (idx >= count || idx < 0 || static_cast<std::string::size_type>(i) < buff.size() || buff.size() == 0) {
		std::cout << "Invalid index argument." << std::endl;
		return;
	}
	contacts[idx].printContact();
};

void PhoneBook::searchContact() {
	std::string buff;

	if (count == 0) {
		std::cout << "Phone Book is empty now.\n";
		return;
	}
	printContactsTable();
	std::cout << "Write the contact index: ";
	getline(std::cin, buff);
	findIndexContact(buff);
}