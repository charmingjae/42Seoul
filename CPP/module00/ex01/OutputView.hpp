/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputView.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:40:09 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 21:25:16 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUTVIEW_HPP
#define OUTPUTVIEW_HPP

#include "Contact.hpp"
#include "OutputView.hpp"
#include <iomanip>
#include <iostream>

class OutputView {
  public:
    OutputView();
    void showPrompt(void);
    void showGoodBye(void);
    void showCommandEOF(void);
    void showSearchPrompt(void);
    void showPhoneBookEmpty(void);
    void showPhoneBookColumn(void);
    void showWhenEnterLastName(void);
    void showWhenEnterNickName(void);
    void showWhenEnterFirstName(void);
    void showNotValidIndexRange(void);
    void showPhoneBookAllColumn(void);
    void showWhenEnterPhoneNumber(void);
    void showAlertEmptySearchindex(void);
    void showWhenEnterDarkestSecret(void);
    void showContactComponentNotValid(void);
    void showSpecContactEmpty(int paramIndex);
    void showAllContacts(Contact *paramPhoneBook);
    std::string manufactLongString(std::string paramString);
    void showSpecContact(Contact paramContact, int paramIndex);
    void showSpecContactComponents(Contact paramContact, int paramIndex,
                                   int realIndex);
};

#endif