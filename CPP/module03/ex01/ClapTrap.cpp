/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:29:14 by mcha              #+#    #+#             */
/*   Updated: 2022/07/03 23:47:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor, Destructor
ClapTrap::ClapTrap()
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor is executed" << std::endl;
}

ClapTrap::ClapTrap(const std::string &paramName)
    : _name(paramName), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    if (this->getName().empty() || paramName.empty()) {
        std::cout << "ClapTrap's name cannot be empty. Exit" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "ClapTrap " << this->getName() << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    if (clapTrap.getName().empty()) {
        std::cout << "ClapTrap's name cannot be empty. Exit" << std::endl;
        exit(EXIT_FAILURE);
    }
    // Bind value
    *this = clapTrap;
    std::cout << "ClapTrap " << this->getName() << " is created" << std::endl;
}

ClapTrap::~ClapTrap() {
    if (this->getName().empty()) {
        std::cout << "ClapTrap unknown is destructed" << std::endl;
    }
    std::cout << "ClapTrap " << this->getName() << " is destructed"
              << std::endl;
}

// operator
ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    this->_name = clapTrap._name;
    this->_hitPoints = clapTrap._hitPoints;
    this->_energyPoints = clapTrap._energyPoints;
    this->_attackDamage = clapTrap._attackDamage;
    std::cout << "Assignment operator is executed" << std::endl;
    return (*this);
}

// function
void ClapTrap::attack(const std::string &target) {
    if (this->isInOperable()) {
        std::cout << "ClapTrap " << this->getName() << " can't attack"
                  << std::endl;
    } else {
        std::cout << "ClapTrap " << this->getName() << " attacks " << target
                  << " , causing " << this->getAttackDamage()
                  << " points of damage !" << std::endl;
        this->_energyPoints -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->isDead()) {
        std::cout << "ClapTrap " << this->getName() << " is already dead."
                  << std::endl;
    } else {
        std::cout << "ClapTrap " << this->getName() << " take " << amount
                  << " damage." << std::endl;
        this->_hitPoints =
            this->_hitPoints -
            (this->getHitPoints() < amount ? this->getHitPoints() : amount);
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->isInOperable()) {
        std::cout << "ClapTrap " << this->getName() << " can't be repaired"
                  << std::endl;
    } else {
        std::cout << "ClapTrap " << this->getName() << " repaired " << amount
                  << " hit points" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
    }
}

// Judge
bool ClapTrap::isInOperable(void) const {
    if (isDead() || isNoEnergy())
        return true;
    return false;
}

bool ClapTrap::isDead(void) const { return (this->getHitPoints() <= 0); }

bool ClapTrap::isNoEnergy(void) const { return (this->getEnergyPoints() <= 0); }

// getter
std::string ClapTrap::getName(void) const { return this->_name; }

unsigned int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }

unsigned int ClapTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}