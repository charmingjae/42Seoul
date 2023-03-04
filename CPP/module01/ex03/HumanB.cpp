/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:04:29 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 19:00:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string paramName) : _name(paramName), _weapon(NULL) {
    std::cout << "[HumanB] " << paramName << " born" << std::endl;
}
HumanB::~HumanB() {
    std::cout << "[HumanB] " << _name << " is dead" << std::endl;
}

void HumanB::attack(void) {
    if (_weapon) {
        std::cout << "[HumanB] " << _name << " attacks with their "
                  << _weapon->getType() << std::endl;
    } else {
        std::cout << "[HumanB] " << _name << " attacks with their hands"
                  << std::endl;
    }
}

void HumanB::setWeapon(Weapon &paramWeapon) { _weapon = &paramWeapon; }
