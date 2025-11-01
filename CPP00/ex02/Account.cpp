/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:29:55 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 16:29:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {return _nbAccounts;}
int	Account::getTotalAmount( void ) {return _totalAmount;}
int	Account::getNbDeposits( void ) {return _totalNbDeposits;}
int	Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}
int		Account::checkAmount( void ) const {return _amount;}

void Account::_displayTimestamp(void)
{
    // std::cout << "[19920104_091532] ";
    std::time_t t = std::time(0);
    std::tm *ltm = std::localtime(&t);

    std::cout << "["
              << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
              << std::setw(2) << std::setfill('0') << ltm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec
              << "] ";
}


Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _accountindex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    std::cout << "index:" << _accountindex
              << ";amount:" << initial_deposit
              << ";created" << std::endl;
    _totalAmount += initial_deposit;

}

Account::~Account()
{
    _displayTimestamp();

    std::cout << "index:" << _accountindex
              << ";amount:" << _amount
              << ";closed" << std::endl;

}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
    
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountindex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    int old_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountindex
              << ";p_amount:" << old_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    int old_amount = _amount;
    if (_amount < withdrawal)
    {
        std::cout << "index:" << _accountindex
          << ";p_amount:" << _amount
          << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -=withdrawal;
    std::cout << "index:" << _accountindex
              << ";p_amount:" << old_amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}
