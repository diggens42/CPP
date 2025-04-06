/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:08:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/13 21:09:10 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t		ts;
	struct tm	*local_time;
	char		buf[20];

	std::time(&ts);
	local_time = std::localtime(&ts);

	std::strftime(buf, 20, "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buf << " ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		// << "accounts:" << Account::getNbAccounts() << ";"
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbAccounts() << ";"
		<< "withdrawals:" << getNbWithdrawals() <<
	std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << checkAmount() << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals <<
	std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << checkAmount() << ";"
		<< "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout
		<< "amount:" << checkAmount() << ";"
		<< "nb_deposits:" << _nbDeposits <<
	std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << checkAmount() << ";"
		<< "withdrawl:";
	if (withdrawal <= checkAmount())
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
 		std::cout
			<< withdrawal << ";"
			<< "amount:" << checkAmount() << ";"
			<< "nb_withdrawals:" << _nbWithdrawals <<
		std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << checkAmount() << ";"
		<< "created" <<
	std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << checkAmount() << ";"
		<< "closed" <<
	std::endl;
}

