/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:08:46 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 18:13:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test00(void) {
    Bureaucrat *obj = new Bureaucrat("mcha", 10);
    std::cout << "[INIT] ";
    std::cout << *obj << std::endl;

    for (int i = 0; i < 10; i++) {
        obj->setIncreGrade();
        std::cout << *obj << std::endl;
    }
    std::cout << *obj << std::endl;

    delete obj;
}

void test01(void) {
    Bureaucrat *obj = new Bureaucrat("mcha", 140);
    std::cout << "[INIT] ";
    std::cout << *obj << std::endl;

    // Decrease grade
    for (int i = 0; i < 11; i++) {
        obj->setDecreGrade();
        std::cout << *obj << std::endl;
    }

    delete obj;
}

void test02(void) {
    Bureaucrat *obj = new Bureaucrat("jule", 140);
    std::cout << "[INIT] ";
    std::cout << *obj << std::endl;
    obj->setDecreGrade();
    std::cout << *obj << std::endl;

    Bureaucrat *mcha = new Bureaucrat(*obj);
    std::cout << "[INIT] ";
    std::cout << *mcha << std::endl;

    delete obj;
    delete mcha;
}

int main(void) {
    try {
        std::cout << "\n=========== Scene 01 ===========\n";
        // test00();
        std::cout << "\n=========== Scene 02 ===========\n";
        test01();
        std::cout << "\n=========== Scene 03 ===========\n";
        test02();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (1);
}