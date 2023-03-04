/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:19:22 by mcha              #+#    #+#             */
/*   Updated: 2022/06/24 13:41:06 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "AboutFile.hpp"
#include <fstream>
#include <iostream>
#include <string>

class Controller {
  private:
  public:
    int proc(std::string paramFileName, std::string paramStrTarget,
             std::string paramStrReplace);
    int checkParamNull(std::string paramFst, std::string paramSec,
                       std::string paramThr);
    int isStringNull(std::string paramStr);
    int isFileOpenedSuccessfully(std::ifstream &paramStream);
    void readAndConnect(std::ifstream &paramStream, AboutFile &paramAboutFile);
    void replaceStr(std::string &paramOrigin, std::string paramTarget,
                    std::string paramReplace);
};

#endif