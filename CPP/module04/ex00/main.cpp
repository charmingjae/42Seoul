/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:58:15 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 13:57:52 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    std::cout << "====================== Scene 01 ======================"
              << std::endl;
    {
        // Animal
        Animal *animal = new Animal();
        std::cout << "Animal type : " << animal->getType() << std::endl;
        animal->makeSound();
        std::cout << std::endl;

        // Cat
        Cat *cat = new Cat();
        std::cout << "Cat type : " << cat->getType() << std::endl;
        cat->makeSound();
        std::cout << std::endl;

        // Dog
        Dog *dog = new Dog();
        std::cout << "Dog type : " << dog->getType() << std::endl;
        dog->makeSound();
        std::cout << std::endl;

        delete animal;
        delete cat;
        delete dog;
    }
    std::cout << "\n====================== Scene 02 ======================"
              << std::endl;
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();
    }
    // system("leaks ex00");
    return (1);
}