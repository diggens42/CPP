/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:08:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/07/12 20:20:44 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
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
void	Account::displayAccountsInfos( void )
{
	std::cout
		<< "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbAccounts << ";"
		<< "withdrawals:" << Account::getNbWithdrawals <<
	std::endl;
}
