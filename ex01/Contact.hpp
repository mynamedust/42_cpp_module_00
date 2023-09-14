#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
private:
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	void setFirstName();

	void setLastName();

	void setNickname();

	void setPhoneNumber();

	void setDarkestSecret();

	void tablePrintField(std::string str);

	std::string userInsert();

public:
	bool fillContact(int idx);

	void print();

	void tablePrint();
};

#endif