#include "./Contact.hpp"

std::string Contact::userInsert() {
	std::string buff;

	getline(std::cin, buff);
	std::cout << "______________________\n";
	if (buff.size() == 0)
		return "";
	return buff;
}

void Contact::setFirstName() {
	std::cout << "Write a first name:" << std::endl;
	firstName = userInsert();
}

void Contact::setLastName() {
	std::cout << "Write a last name:" << std::endl;
	lastName = userInsert();
}

void Contact::setNickname(){
	std::cout << "Write a nickname:" << std::endl;
	nickname = userInsert();
}

void Contact::setPhoneNumber(){
	std::cout << "Write a phone number:" << std::endl;
	phoneNumber = userInsert();
}

void Contact::setDarkestSecret() {
	std::cout << "Write a darkest secret:" << std::endl;
	darkestSecret = userInsert();
};

bool Contact::fillContact(int idx) {
	index = idx;
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
	if (firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
		return false;
	return true;
};

void Contact::print() {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::tablePrintField(std::string str) {
	std::string turnic;

	turnic = str.substr(0, 10);
	if (str.size() > 10)
		turnic += '.';
	std::cout << std::right << std::setw(10) << turnic << '|';
}

void Contact::tablePrint() {
	tablePrintField(std::to_string(index));
	tablePrintField(firstName);
	tablePrintField(lastName);
	tablePrintField(nickname);
	std::cout << std::endl;
}