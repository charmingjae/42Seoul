/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:40:21 by mcha              #+#    #+#             */
/*   Updated: 2022/07/02 01:26:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void showStatus_1(ClapTrap &obj) {
    std::cout << "\n	[Clap] " << obj.getName()
              << "	HP :	" << obj.getHitPoints()
              << "	ENG :	" << obj.getEnergyPoints()
              << "	ATTK :	" << obj.getAttackDamage() << std::endl;
}

void showStatus_2(ScavTrap &obj) {
    std::cout << "	[Scav] " << obj.getName()
              << "	HP :	" << obj.getHitPoints()
              << "	ENG :	" << obj.getEnergyPoints()
              << "	ATTK :	" << obj.getAttackDamage() << "\n"
              << std::endl;
}

void test(void) {
    std::cout << "\n|---------------- Scene 01 ----------------|" << std::endl;
    {
        // Create object
        ClapTrap ori("ori");
        ScavTrap mcha("mcha");
        // Show status
        showStatus_1(ori);
        showStatus_2(mcha);
        std::cout << std::endl;
        // Attack
        mcha.attack("ori");
        ori.takeDamage(mcha.getAttackDamage());
        // Show status
        showStatus_1(ori);
        showStatus_2(mcha);
        // Try repair after dead.
        ori.beRepaired(100);
        // Show status
        showStatus_1(ori);
        showStatus_2(mcha);

        mcha.guardGate();
    }
    std::cout << "\n|---------------- Scene 02 ----------------|" << std::endl;
    {
        ClapTrap *ori = new ClapTrap("ori");
        ClapTrap *mcha = new ScavTrap("mcha");
        ScavTrap *temp = new ScavTrap("Temp");
        // Show status
        showStatus_1(*ori);
        showStatus_1(*mcha);
        std::cout << std::endl;
        // Attack
        mcha->attack("ori");
        ori->takeDamage(mcha->getAttackDamage());
        // Show status
        showStatus_1(*ori);
        showStatus_1(*mcha);
        std::cout << std::endl;
        // Try repair after dead.
        ori->beRepaired(100);
        // Show status
        showStatus_1(*ori);
        showStatus_1(*mcha);
        std::cout << std::endl;

        temp->guardGate();

        delete mcha;
        delete ori;
        delete temp;
    }
}

int main(void) {
    test();
    // system("leaks ex01");
    return (1);
}