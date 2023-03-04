/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:12:39 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 21:34:47 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &paramIce) : AMateria("ice") { *this = paramIce; }

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &paramIce) {
    this->_type = paramIce._type;
    return (*this);
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << "*"
              << std::endl;
}