/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:06:19 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 00:34:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat default constructor is executed." << std::endl;
}

Cat::Cat(const Cat &paramCat) : Animal(paramCat), _brain(NULL) {
    *this = paramCat;
    std::cout << "Cat copy constructor is executed." << std::endl;
}

Cat::~Cat() {
    if (this->_brain)
        delete this->_brain;
    std::cout << "Cat destructor is executed." << std::endl;
}

Cat &Cat::operator=(const Cat &paramCat) {
    this->_type = paramCat._type;
    if (this->_brain) {
        delete this->_brain;
    }
    this->_brain = new Brain();
    for (int i = 0; i < 100; i++) {
        this->_brain->setIdeas(i, this->_brain->getIdeas(i));
    }
    std::cout << "Cat operator= is executed." << std::endl;
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Cat make sound. Meow~" << std::endl;
}

void Cat::setType(std::string paramType) { this->_type = paramType; }

std::string Cat::getType(void) const { return (this->_type); }

Brain *Cat::getBrain(void) const { return (this->_brain); }