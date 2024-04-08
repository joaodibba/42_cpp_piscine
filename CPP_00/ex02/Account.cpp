#include <Account.hpp>
#include <iostream>

// int Account::_nbAccounts = 0;
// int Account::_totalAmount = 0;
// int Account::_totalNbDeposits = 0;
// int Account::_totalNbWithdrawals = 0;
// tolya did this find why it is needed

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}


int	Account::getNbDeposits( void )
{
	return (_nbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_nbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	
}