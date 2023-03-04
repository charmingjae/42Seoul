/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:42:22 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 00:39:06 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() { this->_type = ""; }

AMateria::AMateria(const AMateria &paramAMateria) { *this = paramAMateria; }

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &paramAMateria) {
    this->_type = paramAMateria._type;
    return (*this);
}

std::string const &AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter &target) {
    std::cout << " * just display " << target.getName() << std::endl;
}