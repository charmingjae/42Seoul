/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:32:58 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 20:38:06 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Contact.hpp"
#include "InputView.hpp"
#include "OutputView.hpp"
#include "PhoneBook.hpp"

class Controller {
  private:
    InputView _inputView;
    OutputView _outputView;
    PhoneBook _phoneBook;

  public:
    Controller();
    int process(void);
    /* Check function */
    int isValidIndexRange(int paramIndex);
    int isSpecContactEmpty(int paramIndex);
    int isCommandADD(std::string paramCommand);
    int isCommandEXIT(std::string paramCommand);
    int isContactEmpty(Contact *paramPhoneBook);
    int isMatchCommand(std::string paramCommand);
    int isCommandSEARCH(std::string paramCommand);
    int convertStringToInteger(std::string paramString);
    int isEnteredCommandValid(std::string &paramCommand);
    /* Judge function */
    int judgeAndProcessCommand(std::string paramCommand);
};

#endif