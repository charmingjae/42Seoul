/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:17:26 by mcha              #+#    #+#             */
/*   Updated: 2022/06/29 15:20:49 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &point) { *this = point; }

Point::Point(float num1, float num2) : _x(num1), _y(num2) {}

Point::Point(int num1, int num2) : _x(num1), _y(num2) {}

Point::~Point() {}

Point &Point::operator=(const Point &point) {
    (Fixed &)this->_x = point.getConstX();
    (Fixed &)this->_y = point.getConstY();
    return *this;
}

bool Point::operator==(const Point &point) const {
    return (this->getConstX() == point.getConstX() &&
            this->getConstY() == point.getConstY());
}

Fixed const &Point::getConstX(void) const { return _x; }
Fixed const &Point::getConstY(void) const { return _y; }

std::ostream &operator<<(std::ostream &os, const Point &point) {
    return os << " [ " << point.getConstX() << " , " << point.getConstY()
              << " ] ";
}