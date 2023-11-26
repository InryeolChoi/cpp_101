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
	time_t    ts;
	char    buf[16];

    time(&ts);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << "[" << buf << "]";
}

// 생성자
Account::Account() {}
Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
}

// 중간 검사용
void	 Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawls:" << Account::_totalNbWithdrawals << std::endl;
}

// 출력
void	Account::displayStatus(void) const 
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit) // 예금
{
	int p_amount;

	Account::_displayTimestamp();
	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;

	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits <<std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

int		Account::checkAmount(void) const // 출금 검사
{
	if (Account::_amount >= 0)
		return (1);
	else
		return (0);
}

bool	Account::makeWithdrawal(int withdrawal) // 출금
{
	int p_amount;

	Account::_displayTimestamp();
	p_amount = _amount;
	_amount = _amount - withdrawal;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";

	if (Account::checkAmount())
	{
		_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawls:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
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
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << ";"<< std::endl;
}
