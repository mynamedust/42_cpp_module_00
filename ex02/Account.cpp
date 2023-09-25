#include "Account.hpp"
#include <iostream>

// Init the class static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
	time_t	timeNow;
	std::tm	*timePtr;
	char	timestamp[20];

	timeNow = std::time(nullptr);
	timePtr = std::localtime(&timeNow);
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", timePtr);
	std::cout << "[" << timestamp << "]";
}

int	Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << p_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	bool status;
	int p_amount;

	p_amount = _amount;
	status = checkAmount() >= withdrawal;
	if (status) {
		_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		_nbWithdrawals++;
	}
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << p_amount;
	if (!status) {
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

Account::Account(int initial_deposit) {
	// Init the object variables
	_accountIndex = Account::getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// Increment the class variables
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	// Print object creating log
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}