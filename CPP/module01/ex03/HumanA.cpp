/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:00:06 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 14:24:56 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string paramName, Weapon &paramWeapon)
    : _name(paramName), _weapon(paramWeapon) {
    std::cout << "[HumanA] " << paramName << " created with weapon "
              << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << "[HumanA] " << _name << " is dead" << std::endl;
}

void HumanA::attack(void) {
    std::cout << "[HumanA] " << _name << " attacks with their "
              << _weapon.getType() << std::endl;
}