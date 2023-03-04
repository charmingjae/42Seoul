/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:14:36 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 00:22:59 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// The type of the Animal class can be left empty or set to the value of your
// choice.
Animal::Animal() : _type("") {
    std::cout << "Animal default constructor is executed." << std::endl;
}

Animal::Animal(const Animal &paramAnimal) {
    *this = paramAnimal;
    std::cout << "Animal copy constructor is executed." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor is executed." << std::endl;
}

Animal &Animal::operator=(const Animal &paramAnimal) {
    this->_type = paramAnimal._type;
    std::cout << "Animal operator= is executed." << std::endl;
    return (*this);
}

void Animal::makeSound(void) const {
    std::cout << "Animal make sound. (?)" << std::endl;
}

std::string Animal::getType(void) const { return this->_type; }