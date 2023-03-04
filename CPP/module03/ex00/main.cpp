/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:40:21 by mcha              #+#    #+#             */
/*   Updated: 2022/07/01 16:13:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap mcha("Minjae");
    ClapTrap jule("Jule");

    // mcha attack jule
    for (int i = 0; i < 13; i++) {
        std::cout << i << " ";

        mcha.attack("Jule");
        jule.takeDamage(3);
        std::cout << "		Mcha HP: " << mcha.getHitPoints()
                  << "	ENERGY: " << mcha.getEnergyPoints() << std::endl;
        std::cout << "		Jule HP: " << jule.getHitPoints()
                  << "	ENERGY: " << jule.getEnergyPoints() << std::endl;
        std::cout << "\n";
    }
    std::cout << "|----------------------------------------------------------|"
              << std::endl;
    for (int i = 0; i < 13; i++) {
        std::cout << i << " ";
        jule.attack("Mcha");
        mcha.takeDamage(3);
        std::cout << "		Jule HP: " << jule.getHitPoints()
                  << "	ENERGY: " << jule.getEnergyPoints() << std::endl;
        std::cout << "		Mcha HP: " << mcha.getHitPoints()
                  << "	ENERGY: " << mcha.getEnergyPoints() << std::endl;
        std::cout << "\n";
    }

    return (1);
}