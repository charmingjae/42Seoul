/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:19:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/24 13:40:20 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Controller.hpp"

int Controller::proc(std::string paramFileName, std::string paramStrTarget,
                     std::string paramStrReplace) {
    // Check null parameter
    if (!checkParamNull(paramFileName, paramStrTarget, paramStrReplace)) {
        std::cout << "Null parameter is detected" << std::endl;
        return (0);
    }

    // File read
    AboutFile aboutFile;
    std::ifstream inputStream(paramFileName, std::ios::in);

    if (isFileOpenedSuccessfully(inputStream)) {
        readAndConnect(inputStream, aboutFile);

        std::string ret = aboutFile.getResult();
        replaceStr(ret, paramStrTarget, paramStrReplace);

        // to file
        std::string outFile = paramFileName.append(".replace");
        std::ofstream outputStream(outFile);
        if (outputStream.is_open()) {
            outputStream << ret;
        } else {
            std::cout << "File is not opened." << std::endl;
            return (0);
        }
    } else {
        std::cout << "File is not opened." << std::endl;
        return (0);
    }
    return (1);
}

void Controller::replaceStr(std::string &paramOrigin, std::string paramTarget,
                            std::string paramReplace) {
    size_t pos = paramOrigin.find(paramTarget, 0);

    while (pos != std::string::npos) {
        paramOrigin.erase(pos, paramTarget.length());
        paramOrigin.insert(pos, paramReplace);
        pos += paramReplace.length();
        pos = paramOrigin.find(paramTarget, pos);
    }
}

void Controller::readAndConnect(std::ifstream &paramStream,
                                AboutFile &paramAboutFile) {
    std::string temp;
    paramStream.seekg(0, std::ios::end);
    int sz = paramStream.tellg();
    temp.resize(sz);
    paramStream.seekg(0, std::ios::beg);
    paramStream.read(&temp[0], sz);
    paramAboutFile.addString(temp);
    paramStream.close();
}

int Controller::checkParamNull(std::string paramFst, std::string paramSec,
                               std::string paramThr) {
    return !isStringNull(paramFst) && !isStringNull(paramSec) &&
           !isStringNull(paramThr);
}

int Controller::isStringNull(std::string paramStr) { return paramStr.empty(); }
int Controller::isFileOpenedSuccessfully(std::ifstream &paramStream) {
    return paramStream.is_open();
}