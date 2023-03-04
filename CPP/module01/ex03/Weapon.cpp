/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:50:22 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 14:38:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string paramType) { _type = paramType; }
Weapon::~Weapon() {}

void Weapon::setType(const std::string &paramType) { _type = paramType; }
const std::string &Weapon::getType(void) const { return _type; }