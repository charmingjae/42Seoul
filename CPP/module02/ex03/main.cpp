/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:15:56 by mcha              #+#    #+#             */
/*   Updated: 2022/06/29 20:58:46 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
    // (x, y)
    Point p1(0.0f, 0.0f);
    Point p2(3.0f, 0.0f);
    Point p3(0.0f, 3.0f);

    Point p4(1.1f, 1.1f);

    if (bsp(p1, p2, p3, p4)) {
        std::cout << p4 << " located in the triangle" << std::endl;
    } else {
        std::cout << p4 << " is not located in the triangle" << std::endl;
    }

    return (1);
}