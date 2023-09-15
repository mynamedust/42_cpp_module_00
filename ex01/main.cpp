#include "./PhoneBook.hpp"

bool execCommand(PhoneBook &book) {
	std::string cmd;

	getline(std::cin, cmd);
	if (!cmd.compare("EXIT"))
		return false;
	if (!cmd.compare("ADD")) {
		book.addContact();
		return true;
	}
	if (!cmd.compare("SEARCH")) {
		book.searchContact();
		return true;
	}
	std::cout << "Invalid command." << std::endl;
	return true;
}

void getCommand(PhoneBook &book) {
	while (1) {
		std::cout << "Phone Book: ";
		if (!execCommand(book))
			return;
	}
}

int main() {
	PhoneBook book;

	getCommand(book);
}
