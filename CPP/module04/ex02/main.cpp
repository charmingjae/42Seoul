/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:58:15 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 00:31:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void test01(void) {
    std::cout << "====================== Scene 01 ======================"
              << std::endl;
    {
        Dog *dog = new Dog();
        for (int i = 0; i < 100; i++) {
            dog->getBrain()->setIdeas(i, "dd");
        }
        for (int i = 0; i < 10; i++) {
            std::cout << i << " ";
            std::cout << dog->getBrain()->getIdeas(i) << std::endl;
            // std::cout << copy->getBrain()->getIdeas(i) << std::endl;
        }
        Dog copy(*dog);
        std::cout << copy.getType() << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << i << " ";
            std::cout << copy.getBrain()->getIdeas(i) << std::endl;
            // std::cout << copy->getBrain()->getIdeas(i) << std::endl;
        }
        delete dog;

        std::cout << "\n====================== After destruct "
                     "======================\n"
                  << std::endl;
        std::cout << copy.getType() << std::endl;
        copy.setType("New Dog Type");
        std::cout << copy.getType() << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << i << " ";
            std::cout << copy.getBrain()->getIdeas(i) << std::endl;
        }
        for (int i = 0; i < 50; i++) {
            copy.getBrain()->setIdeas(i, "aa");
        }
        for (int i = 0; i < 10; i++) {
            std::cout << i << " ";
            std::cout << copy.getBrain()->getIdeas(i) << std::endl;
        }
    }
}

void test02(void) {
    Animal **animal = new Animal *[4];
    std::cout
        << "\n====================== Create animal ======================\n"
        << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i << " ";
        if (i % 2 == 0) {
            animal[i] = new Cat();
        } else {
            animal[i] = new Dog();
        }
        std::cout << std::endl;
    }

    std::cout
        << "\n====================== Destroy animal ======================\n"
        << std::endl;
    for (int i = 0; i < 4; i++) {
        delete animal[i];
        animal[i] = NULL;
    }
    delete[] animal;
}

void test03(void) {
    Animal *test = new Dog();
    std::cout << test->getType() << std::endl;
    test->makeSound();

    Dog *test1 = new Dog();
    std::cout << test1->getType() << std::endl;
    Dog test2(*test1);
    std::cout << test2.getType() << std::endl;
}

int main(void) {
    std::cout << "\n====================== TEST01 ======================\n"
              << std::endl;
    test01();

    std::cout << "\n====================== TEST02 ======================\n"
              << std::endl;
    test02();
    std::cout << "\n====================== TEST03 ======================\n"
              << std::endl;
    test03();
    // system("leaks ex02");
    return (1);
}