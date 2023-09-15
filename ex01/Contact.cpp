#include "./Contact.hpp"

std::string Contact::userInsert() {
	std::string buff;

	getline(std::cin, buff);
	std::cout << "______________________" << std::endl;
	if (buff.size() == 0)
		return "";
	return buff;
}

void Contact::setInfo(std::string &field, std::string const &message) {
	std::cout << message << std::endl;
	field = userInsert();
}

void Contact::setIndex(const int idx) {
	index = idx;
}

bool Contact::fillContact() {
	index = 0;
	setInfo(firstName, "Write a first name: ");
	setInfo(lastName ,"Write a last name: ");
	setInfo(nickname, "Write a nickname: ");
	setInfo(phoneNumber ,"Write a phone number: ");
	setInfo(darkestSecret, "Write a darkest secret: ");
	if (firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
		return false;
	std::cout << "Contact successfully added." << std::endl;
	return true;
};

void Contact::printContact() {
	std::cout << "______________________" << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << "______________________" << std::endl;
}

void Contact::tablePrintField(std::string str) {
	std::string turnic;

	turnic = str.substr(0, 10);
	if (str.size() > 10)
		turnic[9] = '.';
	std::cout << std::right << std::setw(10) << turnic << '|';
}

void Contact::tablePrint() {
	tablePrintField(std::to_string(index));
	tablePrintField(firstName);
	tablePrintField(lastName);
	tablePrintField(nickname);
	std::cout << std::endl;
}