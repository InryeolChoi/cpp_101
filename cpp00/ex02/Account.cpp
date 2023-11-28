# include "Account.hpp"
# include <ctime>
# include <iostream>
# include <iomanip>

int		Account::_nbAccounts = 0;
int 	Account::_totalNbWithdrawals = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalAmount = 0;

// util
int 	Account::getNbAccounts() { return (_nbAccounts); }
int 	Account::getTotalAmount() { return (_totalAmount); }
int 	Account::getNbDeposits() { return (_totalNbDeposits); }
int 	Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

void	Account::_displayTimestamp( void )
{
	time_t		ts;
	char		buf[16];

    time(&ts);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << "[" << buf << "]";
}

// 생성자
Account::Account() {}
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	_nbAccounts++;
	_totalAmount += _amount;
}

// 중간 검사용
void	 Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// 출력
void	Account::displayStatus(void) const 
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit) // 예금
{
	int p_amount;

	_displayTimestamp();
	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;

	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits <<std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

int		Account::checkAmount(void) const // 출금 검사
{
	if (_amount >= 0)
		return (1);
	else
		return (0);
}

bool	Account::makeWithdrawal(int withdrawal) // 출금
{
	int p_amount;

	_displayTimestamp();
	p_amount = _amount;
	_amount = _amount - withdrawal;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";

	if (checkAmount())
	{
		_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		_amount = p_amount;
		return (false);
	}
}

// 소멸자
Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}
