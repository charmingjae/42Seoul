/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:20:32 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 00:38:32 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    this->_slot = new AMateria *[4];
    for (int i = 0; i < 4; i++) {
        this->_slot[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &paramMs) { *this = paramMs; }

MateriaSource &MateriaSource::operator=(const MateriaSource &paramMs) {
    if (this->_slot)
        delete[] _slot;
    this->_slot = new AMateria *[4];
    for (int i = 0; i < 4; i++) {
        this->_slot[i] = paramMs._slot[i];
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_slot[i])
            delete this->_slot[i];
    }
    if (this->_slot)
        delete[] _slot;
}

void MateriaSource::learnMateria(AMateria *paramMateria) {
    for (int i = 0; i < 4; i++) {
        if (this->_slot[i] == NULL) {
            this->_slot[i] = paramMateria;
            return;
        }
    }
    delete paramMateria;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->_slot[i] && (this->_slot[i]->getType() == type)) {
            return this->_slot[i]->clone();
        }
    }
    return (0);
}