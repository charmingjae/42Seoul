/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:49 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 20:43:11 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { _idx = 0; }

int PhoneBook::addNewContact(Contact paramContact) {
    _phoneBook[getNowIndex() % 8] = paramContact;
    increaseIndex();
    return (1);
}

Contact PhoneBook::getSpecContact(int paramIdx) { return _phoneBook[paramIdx]; }

int PhoneBook::getNowIndex(void) { return _idx; }

void PhoneBook::increaseIndex(void) { _idx++; }

Contact *PhoneBook::getAllContact(void) { return _phoneBook; }