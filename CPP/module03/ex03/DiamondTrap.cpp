/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:21:44 by mcha              #+#    #+#             */
/*   Updated: 2022/07/04 13:59:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor is executed." << std::endl;
    // Bind Value
    this->_name = "";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string &paramName)
    : ClapTrap(paramName + "_clap_name"), ScavTrap(paramName),
      FragTrap(paramName) {
    this->_name = paramName;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " is created " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
    std::cout << "DiamondTrap with copy constructor is created" << std::endl;
    *this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    std::cout << "DiamondTrap's assignment operator is executed." << std::endl;
    this->_name = diamondTrap._name;
    this->_hitPoints = diamondTrap._hitPoints;
    this->_energyPoints = diamondTrap._energyPoints;
    this->_attackDamage = diamondTrap._attackDamage;
    return (*this);
}

void DiamondTrap::whoAmI() {
    std::cout << "Diamond name : " << _name
              << " 	Clap name : " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->_name << " is destructed" << std::endl;
}