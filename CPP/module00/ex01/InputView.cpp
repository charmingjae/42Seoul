/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputView.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:36:24 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 20:17:11 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputView.hpp"

InputView::InputView() {}

int InputView::enterSearchIndex(std::string &paramInput) {
    std::string inputString;

    while (true) {
        OutputView outputView;

        outputView.showSearchPrompt();
        if (!std::getline(std::cin, inputString)) {
            outputView.showCommandEOF();
            return (0);
        }
        if (checkDigit(inputString)) {
            if (inputString.length() > 0) {
                paramInput = inputString;
                break;
            } else
                outputView.showAlertEmptySearchindex();
        }
    }
    return (1);
}

int InputView::checkDigit(std::string paramString) {
    for (size_t i = 0; i < paramString.length(); i++) {
        if (!isdigit(paramString[i]))
            return (0);
    }
    return (1);
}

int InputView::enterCommand(std::string &paramCommand) {
    if (!std::getline(std::cin, paramCommand)) {
        return (0);
    }
    return (1);
}

int InputView::enterContactComponent(std::string (&paramInput)[5]) {
    OutputView outputView;

    for (int i = 0; i < 5; i++) {
        getInputTheme(outputView, i);
        if (!std::getline(std::cin, paramInput[i])) {
            outputView.showCommandEOF();
            return (0);
        }
        if (!checkContactComponentValid(paramInput[i])) {
            outputView.showContactComponentNotValid();
            i--;
            continue;
        }
    }
    return (1);
}

int InputView::checkContactComponentValid(std::string paramInput) {
    return paramInput.length() > 0;
}

void InputView::getInputTheme(OutputView paramOutputView, int paramIndex) {
    if (paramIndex == 0)
        paramOutputView.showWhenEnterFirstName();
    if (paramIndex == 1)
        paramOutputView.showWhenEnterLastName();
    if (paramIndex == 2)
        paramOutputView.showWhenEnterNickName();
    if (paramIndex == 3)
        paramOutputView.showWhenEnterPhoneNumber();
    if (paramIndex == 4)
        paramOutputView.showWhenEnterDarkestSecret();
}