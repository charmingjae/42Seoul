/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:02:48 by mcha              #+#    #+#             */
/*   Updated: 2022/07/14 14:31:36 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _value(0) {}

Data::Data(const Data &src) : _value(src._value) { *this = src; }

Data::~Data() {}

Data &Data::operator=(const Data &rhs) {
    this->_value = rhs._value;
    return (*this);
}

int Data::getValue(void) { return static_cast<int>(this->_value); }

void Data::setValue(int param) { this->_value = param; }