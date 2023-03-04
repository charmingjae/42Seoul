/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:31:22 by mcha              #+#    #+#             */
/*   Updated: 2022/07/03 23:44:38 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor is executed." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &paramName) : ClapTrap(paramName) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
    std::cout << "FragTrap's copy constructor is executed." << std::endl;
    *this = fragTrap;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " is destructed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    std::cout << "FragTrap's assignment operator is executed." << std::endl;
    this->_name = fragTrap._name;
    this->_hitPoints = fragTrap._hitPoints;
    this->_energyPoints = fragTrap._energyPoints;
    this->_attackDamage = fragTrap._attackDamage;
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    if (this->isDead()) {
        std::cout << "FragTrap " << this->getName() << " is already dead ..."
                  << std::endl;
    } else {
        std::cout << "FragTrap " << this->getName() << " high-five!"
                  << std::endl;
    }
}