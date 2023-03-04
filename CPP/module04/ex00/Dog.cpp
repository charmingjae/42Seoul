/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:10:32 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 17:23:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog default constructor is executed." << std::endl;
}

Dog::Dog(const Dog &paramDog) : Animal() {
    *this = paramDog;
    std::cout << "Dog copy constructor is executed." << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor is executed." << std::endl; }

Dog &Dog::operator=(const Dog &paramDog) {
    this->_type = paramDog._type;
    std::cout << "Dog operator= is executed." << std::endl;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Dog make sound. Bark!" << std::endl;
}