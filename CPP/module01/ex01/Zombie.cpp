/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:14:36 by mcha              #+#    #+#             */
/*   Updated: 2022/06/22 21:42:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() { std::cout << "new zombie born!" << std::endl; };
Zombie::~Zombie() { std::cout << _name << " : good bye ~" << std::endl; }

void Zombie::announce(void) {
    std::cout << _name << " : Brainzzzzzzzzzzzzz......." << std::endl;
}

void Zombie::setName(std::string paramName) { _name = paramName; }
std::string Zombie::getName(void) { return _name; }