/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:10:32 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 17:24:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog default constructor is executed." << std::endl;
}

Dog::Dog(const Dog &paramDog) : Animal(paramDog), _brain(NULL) {
    *this = paramDog;
    std::cout << "Dog copy constructor is executed." << std::endl;
}

Dog::~Dog() {
    if (this->_brain)
        delete _brain;
    std::cout << "Dog destructor is executed." << std::endl;
}

Dog &Dog::operator=(const Dog &paramDog) {
    this->_type = paramDog._type;
    if (this->_brain) {
        delete this->_brain;
    }
    this->_brain = new Brain();
    for (int i = 0; i < 100; i++) {
        this->_brain->setIdeas(i, this->_brain->getIdeas(i));
    }
    std::cout << "Dog operator= is executed." << std::endl;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Dog make sound. Bark!" << std::endl;
}

void Dog::setType(std::string paramType) { this->_type = paramType; }

std::string Dog::getType(void) const { return (this->_type); }

Brain *Dog::getBrain(void) const { return (this->_brain); }