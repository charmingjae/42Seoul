/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:52:56 by mcha              #+#    #+#             */
/*   Updated: 2022/06/29 20:58:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool isSamePoint(Point const &a, Point const &b, Point const &c,
                 Point const &p) {
    if (a == b || b == c || a == c || a == p || b == p || c == p)
        return true;
    return false;
}

bool isCollinear(Fixed const x1, Fixed const y1, Fixed const x2, Fixed const y2,
                 Fixed const x3, Fixed const y3) {
    Fixed ret(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    if (ret == Fixed(0))
        return true;
    return false;
}

bool isSameLine(Point const &a, Point const &b, Point const &c,
                Point const &p) {
    if (isCollinear(a.getConstX(), a.getConstY(), b.getConstX(), b.getConstY(),
                    c.getConstX(), c.getConstY())) {
        return true;
    }
    if (isCollinear(a.getConstX(), a.getConstY(), b.getConstX(), b.getConstY(),
                    p.getConstX(), p.getConstY())) {
        return true;
    }
    if (isCollinear(a.getConstX(), a.getConstY(), c.getConstX(), c.getConstY(),
                    p.getConstX(), p.getConstY())) {
        return true;
    }
    if (isCollinear(b.getConstX(), b.getConstY(), c.getConstX(), c.getConstY(),
                    p.getConstX(), p.getConstY())) {
        return true;
    }
    return false;
}

float getAbs(float nbr) { return (nbr < 0 ? nbr * -1 : nbr); }

Fixed getAreaSize(Fixed const x1, Fixed const y1, Fixed const x2,
                  Fixed const y2, Fixed const x3, Fixed const y3) {
    Fixed ret(getAbs(
        (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)).toFloat() / 2.0f));
    return (ret);
}

Fixed getCompArea(Point const &a, Point const &b, Point const &c,
                  Point const &p) {
    Fixed abp(getAreaSize(a.getConstX(), a.getConstY(), b.getConstX(),
                          b.getConstY(), p.getConstX(), p.getConstY()));
    Fixed bcp(getAreaSize(b.getConstX(), b.getConstY(), c.getConstX(),
                          c.getConstY(), p.getConstX(), p.getConstY()));
    Fixed acp(getAreaSize(a.getConstX(), a.getConstY(), c.getConstX(),
                          c.getConstY(), p.getConstX(), p.getConstY()));
    return (Fixed(abp + bcp + acp));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    if (isSamePoint(a, b, c, point)) {
        return false;
    } else if (isSameLine(a, b, c, point)) {
        return false;
    }

    // original area(size)
    Fixed ori(getAreaSize(a.getConstX(), a.getConstY(), b.getConstX(),
                          b.getConstY(), c.getConstX(), c.getConstY()));
    // compare area(size)
    Fixed comp(getCompArea(a, b, c, point));

    if (ori == comp) {
        return true;
    } else
        return false;
}