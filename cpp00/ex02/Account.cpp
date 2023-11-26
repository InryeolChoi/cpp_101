# include "Account.hpp"
# include <iostream>
# include <iomanip>

int		Account::_nbAccounts = 0;
int 	Account::_totalNbWithdrawals = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalAmount = 0;

void	Account::_displayTimestamp( void )
{
    time_t time_now = time(NULL);
    struct tm *pLocal = localtime(&time_now);
    std::cout << '[' << pLocal->tm_year + 1900 << pLocal->tm_mon << pLocal-> tm_mday << "_"
    << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] ";
}

// 객체 초기화
Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
}

int 	Account::getNbAccounts() {
	return (_nbAccounts);
}

int 	Account::getTotalAmount() {
	return (_totalAmount);
}

int 	Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int 	Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

void	 Account::displayAccountsInfos()
{
	Account();

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account()
{
	Account();
	_amount = initial_deposit;
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount + deposit << ";";
    std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    if (_amount - withdrawal > 0)
    {
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << _amount - withdrawal << ";";
        std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    else
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amonut:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals" << _nbWithdrawals << std::endl;
}
