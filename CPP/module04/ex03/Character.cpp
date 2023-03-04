/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:52:56 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 12:29:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character() : ICharacter() {
    this->_name = "unknown";
    this->_slot = new AMateria *[4];
    for (int i = 0; i < 4; i++) {
        this->_slot[i] = NULL;
    }
}

Character::Character(const Character &paramCharacter) : ICharacter() {
    this->_slot = NULL;
    *this = paramCharacter;
}

Character::Character(const std::string &paramName) : ICharacter() {
    this->_name = paramName;
    this->_slot = new AMateria *[4];
    for (int i = 0; i < 4; i++) {
        this->_slot[i] = NULL;
    }
}

Character &Character::operator=(const Character &paramCharacter) {
    this->_name = paramCharacter.getName();
    if (this->_slot)
        delete[] _slot;
    this->_slot = new AMateria *[4];
    for (int i = 0; i < 4; i++) {
        this->_slot[i] = paramCharacter._slot[i];
    }
    return (*this);
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_slot[i])
            delete this->_slot[i];
    }
    if (this->_slot)
        delete[] _slot;
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->_slot[i] == NULL) {
            this->_slot[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        if (this->_slot[idx] != NULL) {
            // delete this->_slot[idx];
            this->_slot[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4) {
        if (this->_slot[idx] != NULL)
            this->_slot[idx]->use(target);
    }
}
