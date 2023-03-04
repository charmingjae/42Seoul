/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputView.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:41:03 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 21:31:38 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OutputView.hpp"

OutputView::OutputView() {}

void OutputView::showAllContacts(Contact *paramPhoneBook) {
    showPhoneBookColumn();
    for (int i = 0; i < 8; i++) {
        if (!paramPhoneBook[i].getFirstName().empty()) {
            std::cout << " | " << std::setw(10) << i << " | " << std::setw(10)
                      << manufactLongString(paramPhoneBook[i].getFirstName())
                      << " | " << std::setw(10)
                      << manufactLongString(paramPhoneBook[i].getLastName())
                      << " | " << std::setw(10)
                      << manufactLongString(paramPhoneBook[i].getNickName())
                      << " | " << std::endl;
        }
    }
}

void OutputView::showSpecContact(Contact paramContact, int paramIndex) {
    for (int i = 0; i < 6; i++) {
        showSpecContactComponents(paramContact, i, paramIndex);
    }
}

void OutputView::showSpecContactComponents(Contact paramContact, int paramIndex,
                                           int realIndex) {
    if (paramIndex == 0) {
        std::cout << " | " << std::setw(10) << "INDEX"
                  << " | " << realIndex << std::endl;
    }
    if (paramIndex == 1) {
        std::cout << " | " << std::setw(10) << "FIRST NAME"
                  << " | " << paramContact.getFirstName() << std::endl;
    }
    if (paramIndex == 2) {
        std::cout << " | " << std::setw(10) << "LAST NAME"
                  << " | " << paramContact.getLastName() << std::endl;
    }
    if (paramIndex == 3) {
        std::cout << " | " << std::setw(10) << "NICK NAME"
                  << " | " << paramContact.getNickName() << std::endl;
    }
    if (paramIndex == 4) {
        std::cout << " | " << std::setw(10) << "PHONE NBR."
                  << " | " << paramContact.getPhoneNumber() << std::endl;
    }
    if (paramIndex == 5) {
        std::cout << " | " << std::setw(10) << "DARK. SEC."
                  << " | " << paramContact.getDarkestSecret() << std::endl;
    }
}

void OutputView::showSpecContactEmpty(int paramIndex) {
    std::cout << paramIndex << " contact is empty" << std::endl;
}

void OutputView::showNotValidIndexRange(void) {
    std::cout << "Not valid index range. Try again" << std::endl;
}

void OutputView::showSearchPrompt(void) { std::cout << " >> "; }

void OutputView::showPhoneBookEmpty(void) {
    std::cout << "PhoneBook is now empty" << std::endl;
}

void OutputView::showAlertEmptySearchindex(void) {
    std::cout << "Cannot input empty search index. Try again" << std::endl;
}

void OutputView::showPrompt(void) { std::cout << " $ "; }

void OutputView::showPhoneBookAllColumn(void) {
    std::cout << " | " << std::setw(10) << "INDEX"
              << " | " << std::setw(10) << "FIRST NAME"
              << " | " << std::setw(10) << "LAST NAME"
              << " | " << std::setw(10) << "NICK NAME"
              << " | " << std::setw(10) << "PHONE NBR."
              << " | " << std::setw(10) << "DARK. SEC."
              << " | " << std::endl;
}

void OutputView::showPhoneBookColumn(void) {
    std::cout << " | " << std::setw(10) << "INDEX"
              << " | " << std::setw(10) << "FIRST NAME"
              << " | " << std::setw(10) << "LAST NAME"
              << " | " << std::setw(10) << "NICK NAME"
              << " | " << std::endl;
}

void OutputView::showCommandEOF(void) {
    std::cout << std::endl;
    std::cout << "EOF" << std::endl;
}

void OutputView::showWhenEnterFirstName(void) {
    std::cout << std::setw(20) << "FIRST NAME : ";
}

void OutputView::showWhenEnterLastName(void) {
    std::cout << std::setw(20) << "LAST NAME : ";
}

void OutputView::showWhenEnterNickName(void) {
    std::cout << std::setw(20) << "NICK NAME : ";
}

void OutputView::showWhenEnterPhoneNumber(void) {
    std::cout << std::setw(20) << "PHONE NUMBER : ";
}

void OutputView::showWhenEnterDarkestSecret(void) {
    std::cout << std::setw(20) << "DARKEST SECRET : ";
}

void OutputView::showContactComponentNotValid(void) {
    std::cout << "Entered contact component is not valid. Try again"
              << std::endl;
}

void OutputView::showGoodBye(void) {
    std::cout << std::endl;
    std::cout << "Good Bye" << std::endl;
}

std::string OutputView::manufactLongString(std::string paramString) {
    if (paramString.length() > 10) {
        paramString = paramString.substr(0, 10);
        paramString = paramString.replace(9, 1, ".");
    }
    return (paramString);
}