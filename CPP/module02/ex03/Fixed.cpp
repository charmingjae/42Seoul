/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:18:00 by mcha              #+#    #+#             */
/*   Updated: 2022/06/29 20:53:33 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac = 8;

// Constructor

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::Fixed(const int param) : _value(roundf(param * (1 << _frac))) {}

Fixed::Fixed(const float param) : _value(roundf(param * (1 << _frac))) {}

Fixed::~Fixed() {}

// Operator
Fixed &Fixed::operator=(const Fixed &fixed) {
    this->setRawBits(fixed.getRawBits());
    return *this;
}

bool Fixed::operator<(const Fixed &fixed) const {
    return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>(const Fixed &fixed) const {
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    Fixed ret;
    ret.setRawBits(this->getRawBits() + fixed.getRawBits());
    return ret;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    Fixed ret;
    ret.setRawBits(this->getRawBits() - fixed.getRawBits());
    return ret;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    Fixed ret;
    ret.setRawBits(this->getRawBits() * fixed.getRawBits() / (1 << _frac));
    return ret;
}

// Consider divide by zero
Fixed Fixed::operator/(const Fixed &fixed) const {
    if (fixed.getRawBits() == 0)
        std::cout << "Divide by zero. Exception occured" << std::endl;
    Fixed ret;
    ret.setRawBits(this->getRawBits() / fixed.getRawBits() * (1 << _frac));
    return ret;
}

Fixed &Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed f(*this);
    this->setRawBits(this->getRawBits() + 1);
    return f;
}

Fixed &Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed f(*this);
    this->setRawBits(this->getRawBits() - 1);
    return f;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (b.getRawBits() < a.getRawBits()) ? b : a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (b.getRawBits() < a.getRawBits()) ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (b.getRawBits() > a.getRawBits()) ? b : a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (b.getRawBits() > a.getRawBits()) ? b : a;
}

// etc

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