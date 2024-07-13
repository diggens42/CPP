/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:08:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/13 18:04:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return(Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return(Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return(Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return(Account::_totalNbWithdrawals);
}

void	_displayTimestamp( void )
{
	time_t		ts;
	struct tm	*local_time;
	char		buf[20];

	time(&ts);
	local_time = localtime(&ts);

	strftime(buf, 20, "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buf << " ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbAccounts << ";"
		<< "withdrawals:" << Account::getNbWithdrawals <<
	std::endl;
}

void	Account::makeDeposit( int deposit )
{
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits <<
	std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawl:";
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
 		std::cout
			<< withdrawal << ";"
			<< "amount:" << _amount << ";"
			<< "nb_withdrawals:" << _nbWithdrawals <<
		std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}
