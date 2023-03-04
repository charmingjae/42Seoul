/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:18:00 by mcha              #+#    #+#             */
/*   Updated: 2022/06/27 19:41:37 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int param) : _value(roundf(param * (1 << _frac))) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float param) : _value(roundf(param * (1 << _frac))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(fixed.getRawBits());
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return (_value); }

void Fixed::setRawBits(int const raw) { _value = raw; }

int Fixed::toInt(void) const {
    return static_cast<int>(roundf(this->getRawBits() / (1 << _frac)));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->getRawBits()) / (1 << _frac);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}