/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:27:05 by mcha              #+#    #+#             */
/*   Updated: 2022/06/22 20:51:03 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string paramName) : _name(paramName) {
    std::cout << _name << " born" << std::endl;
}
Zombie::~Zombie() {
    std::cout << _name << "		: good bye" << std::endl;
}
void Zombie::announce(void) {
    std::cout << _name << "		: BraiiiiiiinnnzzzZ..." << std::endl;
}