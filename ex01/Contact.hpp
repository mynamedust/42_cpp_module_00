#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	void setFirstName(std::string first);

	void setLastName(std::string last);

	void setNickname(std::string nickname);

	void setPhoneNumber(std::string number);

	void setDarkestSecret(std::string secret);

public:
	void setContact();
};

#endif CONTACT_HPP
