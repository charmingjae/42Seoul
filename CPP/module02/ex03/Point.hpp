/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:14:52 by mcha              #+#    #+#             */
/*   Updated: 2022/06/29 15:19:51 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  private:
    Fixed const _x;
    Fixed const _y;

  public:
    Point();
    Point(const Point &point);
    Point(const float num1, const float num2);
    Point(const int num1, const int num2);
    ~Point();

    Point &operator=(const Point &point);

    bool operator==(const Point &point) const;

    Fixed const &getConstX(void) const;
    Fixed const &getConstY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &os, const Point &point);

#endif