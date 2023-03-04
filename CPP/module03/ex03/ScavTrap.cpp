/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:30:12 by mcha              #+#    #+#             */
/*   Updated: 2022/07/04 14:02:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor is executed." << std::endl;
    // Bind value
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &paramName) : ClapTrap(paramName) {
    // this->_name = paramName;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << paramName << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
    std::cout << "ScavTrap's copy constructor is executed." << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " is destructed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    std::cout << "ScavTrap's assignment operator is executed." << std::endl;
    this->_name = scavTrap._name;
    this->_hitPoints = scavTrap._hitPoints;
    this->_energyPoints = scavTrap._energyPoints;
    this->_attackDamage = scavTrap._attackDamage;
    return (*this);
}

void ScavTrap::attack(const std::string &target) {
    if (this->isInOperable()) {
        std::cout << "ScavTrap " << this->_name << " can't attack" << std::endl;
    } else {
        std::cout << "ScavTrap " << this->_name << " attacks " << target
                  << " , causing " << this->_attackDamage
                  << " points of damage !" << std::endl;
        this->_energyPoints -= 1;
    }
}

void ScavTrap::guardGate(void) {
    if (this->isDead()) {
        std::cout << "ScavTrap " << this->_name << " is not gate keeper mode"
                  << std::endl;
    } else {
        std::cout << "ScavTrap " << this->_name << " is now on gate keeper mode"
                  << std::endl;
    }
}
