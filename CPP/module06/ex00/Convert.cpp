/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:26:46 by mcha              #+#    #+#             */
/*   Updated: 2022/07/14 14:04:16 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _value(0.0), _input(NULL) {}

Convert::Convert(const char *paramValue)
    : _value(strtod(paramValue, &this->_ptr)), _input(paramValue) {}

Convert::Convert(const Convert &src)
    : _value(src._value), _input(src._input), _ptr(src._ptr) {}

Convert &Convert::operator=(const Convert &src) {
    this->_ptr = src._ptr;
    return (*this);
}

Convert::~Convert() {}

void Convert::process(void) const {
    std::string s = this->_input;

    if (s == "nan")
        printNaN();
    else
        printConvert();
}

// char print function
void Convert::printChar(double param) const {
    char conv = static_cast<char>(param);

    if (isnan(param)) {
        std::cout << "char: impossible" << std::endl;
    } else if (param > std::numeric_limits<char>::max() ||
               param < std::numeric_limits<char>::min()) {
        std::cout << "char: impossible" << std::endl;
    } else if (conv >= 32 && conv <= 127) {
        std::cout << "char: '" << conv << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

// int print function
void Convert::printInt(double param) const {
    int conv = static_cast<int>(param);

    if (isnan(param)) {
        std::cout << "int: impossible" << std::endl;
    } else if (param < std::numeric_limits<int>::min() ||
               param > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << conv << std::endl;
    }
}

// float print function
void Convert::printFloat(double param) const {
    float conv = static_cast<float>(param);

    if (isnan(param) || isinf(conv)) {
        if (conv >= 0.0f)
            std::cout << "float: +" << conv << "f" << std::endl;
        else
            std::cout << "float: " << conv << "f" << std::endl;
    } else {
        if (conv == static_cast<int>(conv))
            std::cout << "float: " << conv << ".0";
        else
            std::cout << "float: " << conv;
        std::cout << "f" << std::endl;
    }
}

// double print function
void Convert::printDouble(double param) const {
    if (isnan(param) || isinf(param)) {
        if (param >= 0.0)
            std::cout << "double: +" << param << std::endl;
        else
            std::cout << "double: " << param << std::endl;
    } else {
        if (param == static_cast<int>(param))
            std::cout << "double: " << param << ".0" << std::endl;
        else
            std::cout << "double: " << param << std::endl;
    }
}

void Convert::printNaN(void) const {
    printChar(NAN);
    printInt(NAN);
    printFloat(NAN);
    printDouble(NAN);
}

void Convert::printConvert(void) const {
    double conv;

    if (this->_ptr == this->_input) {
        conv = *(this->_ptr);
    } else {
        conv = this->_value;
    }
    printChar(conv);
    printInt(conv);
    printFloat(conv);
    printDouble(conv);
}