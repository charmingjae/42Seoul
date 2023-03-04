/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:06:19 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 00:34:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat default constructor is executed." << std::endl;
}

Cat::Cat(const Cat &paramCat) : Animal() {
    *this = paramCat;
    std::cout << "Cat copy constructor is executed." << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor is executed." << std::endl; }

Cat &Cat::operator=(const Cat &paramCat) {
    this->_type = paramCat._type;
    std::cout << "Cat operator= is executed." << std::endl;
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Cat make sound. Meow~" << std::endl;
}