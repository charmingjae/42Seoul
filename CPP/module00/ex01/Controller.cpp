/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:34:24 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 20:40:59 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Controller.hpp"

Controller::Controller() {}

int Controller::process(void) {
    while (true) {
        std::string command;

        _outputView.showPrompt();
        if (!isEnteredCommandValid(command)) {
            _outputView.showCommandEOF();
            return (0);
        }
        if (isMatchCommand(command)) {
            if (!judgeAndProcessCommand(command)) {
                return (0);
            }
        }
    }
    return (1);
}

int Controller::judgeAndProcessCommand(std::string paramCommand) {
    if (isCommandADD(paramCommand)) {
        std::string input[5];

        if (!_inputView.enterContactComponent(input)) {
            return (0);
        }
        _phoneBook.addNewContact(
            Contact(input[0], input[1], input[2], input[3], input[4]));
    }
    if (isCommandSEARCH(paramCommand)) {
        if (!isContactEmpty(_phoneBook.getAllContact())) {
            _outputView.showAllContacts(_phoneBook.getAllContact());
            std::string inputIndex;
            if (!_inputView.enterSearchIndex(inputIndex)) {
                return (0);
            }
            if (!isValidIndexRange(convertStringToInteger(inputIndex))) {
                _outputView.showNotValidIndexRange();
            } else {
                int tmpIndex = convertStringToInteger(inputIndex);
                if (!isSpecContactEmpty(tmpIndex)) {
                    _outputView.showSpecContact(
                        _phoneBook.getSpecContact(tmpIndex), tmpIndex);
                } else {
                    _outputView.showSpecContactEmpty(tmpIndex);
                }
            }
        } else {
            _outputView.showPhoneBookEmpty();
        }
    }
    if (isCommandEXIT(paramCommand)) {
        _outputView.showGoodBye();
        return (0);
    }
    return (1);
}

int Controller::convertStringToInteger(std::string paramString) {
    int ret = 0;

    if (paramString.length() > 0) {
        for (size_t idx = 0; idx < paramString.length(); idx++) {
            ret *= 10;
            ret += (paramString[idx] - '0');
        }
        return (ret);
    }
    return (-1);
}

int Controller::isSpecContactEmpty(int paramIndex) {
    return _phoneBook.getSpecContact(paramIndex).getFirstName().empty();
}

int Controller::isContactEmpty(Contact *paramPhoneBook) {
    return paramPhoneBook[0].getFirstName().empty();
}

int Controller::isEnteredCommandValid(std::string &paramCommand) {
    return (_inputView.enterCommand(paramCommand));
}

int Controller::isMatchCommand(std::string paramCommand) {
    if (isCommandADD(paramCommand))
        return (1);
    if (isCommandSEARCH(paramCommand))
        return (1);
    if (isCommandEXIT(paramCommand))
        return (1);
    return (0);
}

int Controller::isCommandADD(std::string paramCommand) {
    return paramCommand.compare("ADD") == 0;
}

int Controller::isCommandSEARCH(std::string paramCommand) {
    return paramCommand.compare("SEARCH") == 0;
}

int Controller::isCommandEXIT(std::string paramCommand) {
    return paramCommand.compare("EXIT") == 0;
}

int Controller::isValidIndexRange(int paramIndex) {
    return (paramIndex >= 0 && paramIndex < 8);
}
