/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:46:49 by mcha              #+#    #+#             */
/*   Updated: 2022/06/22 15:46:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {}
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;     // Set account index
    _nbAccounts++;                   // Increase account index
    _amount = initial_deposit;       // Set account init value
    _totalAmount += initial_deposit; // Set total
    _nbDeposits = 0;                 // set account init deposit
    _nbWithdrawals = 0;              // set account init withdrawals

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount - deposit << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;
}

int Account::checkAmount(void) const { return _amount; }

bool Account::makeWithdrawal(int withdrawal) {
    int flag = false;
    if (checkAmount() >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";"
                  << "p_amount:" << _amount + withdrawal << ";"
                  << "withdrawal:" << withdrawal << ";"
                  << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        flag = true;
    } else {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";"
                  << "p_amount:" << _amount << ";"
                  << "withdrawal:refused" << std::endl;
    }
    return (flag);
}

std::string getCurrentTimestamp(void) {
    time_t t = time(NULL);
    struct tm *tstruct = localtime(&t);
    char buf[16];
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", tstruct);
    return (buf);
}

void Account::_displayTimestamp(void) {
    std::cout << "[" << getCurrentTimestamp() << "] ";
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }