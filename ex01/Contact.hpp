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

	void setInfo(std::string &field, std::string const &message);

	void tablePrintField(std::string str);

	std::string userInsert();

public:
	bool fillContact();

	void printContact();

	void tablePrint();

	void setIndex(int const idx);
};

#endif