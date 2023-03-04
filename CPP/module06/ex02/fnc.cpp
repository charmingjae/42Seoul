/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:17:18 by mcha              #+#    #+#             */
/*   Updated: 2022/07/14 15:46:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.hpp"

int getRandomNumber(void) {
    static bool check = true;
    if (check) {
        std::srand(std::time(NULL));
        check = false;
    }
    int random_variable = std::rand();
    return random_variable % 3;
}

Base *generate(void) {
    int randNumber = getRandomNumber();

    if (randNumber == 0) {
        std::cout << "A generated" << std::endl;
        return new A();
    } else if (randNumber == 1) {
        std::cout << "B generated" << std::endl;
        return new B();
    } else if (randNumber == 2) {
        std::cout << "C generated" << std::endl;
        return new C();
    }
    return (NULL);
}

void identify(Base *p) {
    if (p == NULL) {
        std::cout << "Pointer cast result : NULL" << std::endl;
    } else if (dynamic_cast<A *>(p)) {
        std::cout << "Pointer cast result : A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "Pointer cast result : B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "Pointer cast result : C" << std::endl;
    } else {
        std::cout << "Pointer cast result : Unknown" << std::endl;
    }
}

bool castA(Base &p) {
    try {
        A a = dynamic_cast<A &>(p);
        return true;
    } catch (std::bad_cast &e) {
        return false;
    }
}

bool castB(Base &p) {
    try {
        B b = dynamic_cast<B &>(p);
        return true;
    } catch (std::bad_cast &e) {
        return false;
    }
}

bool castC(Base &p) {
    try {
        C c = dynamic_cast<C &>(p);
        return true;
    } catch (std::bad_cast &e) {
        return false;
    }
}

void identify(Base &p) {
    if (castA(p)) {
        std::cout << "Reference cast result : A" << std::endl;
    } else if (castB(p)) {
        std::cout << "Reference cast result : B" << std::endl;
    } else if (castC(p)) {
        std::cout << "Reference cast result : C" << std::endl;
    } else {
        std::cout << "Reference cast result : Unknown" << std::endl;
    }
}