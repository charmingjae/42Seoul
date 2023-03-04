/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:18:11 by mcha              #+#    #+#             */
/*   Updated: 2022/07/14 15:48:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.hpp"

void proc(void) {
    for (int i = 0; i < 10; i++) {
        Base *b = generate();
        identify(b);
        identify(*b);
        std::cout << std::endl;
        delete b;
    }
}

int main(void) {
    proc();
    return (0);
}