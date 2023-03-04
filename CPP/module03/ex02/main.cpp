/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:40:21 by mcha              #+#    #+#             */
/*   Updated: 2022/07/02 01:32:49 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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

void showStatus_3(FragTrap &obj) {
    std::cout << "	[Frag] " << obj.getName()
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
        FragTrap jule("jule");
        // Show status
        showStatus_1(ori);
        showStatus_2(mcha);
        showStatus_3(jule);
        std::cout << std::endl;
        // Attack
        mcha.attack("ori");
        ori.takeDamage(mcha.getAttackDamage());
        jule.attack("mcha");
        mcha.takeDamage(jule.getAttackDamage());
        // Show status
        showStatus_1(ori);
        showStatus_2(mcha);
        showStatus_3(jule);
        // Try repair after dead.
        ori.beRepaired(100);
        mcha.beRepaired(10);
        // Show status
        showStatus_1(ori);
        showStatus_2(mcha);
        showStatus_3(jule);

        mcha.guardGate();
        jule.highFivesGuys();
    }
    std::cout << "\n|---------------- Scene 02 ----------------|" << std::endl;
    {
        ClapTrap *ori = new ClapTrap("ori");
        ClapTrap *mcha = new ScavTrap("mcha");
        ClapTrap *jule = new FragTrap("jule");
        ScavTrap *temp = new ScavTrap("Temp");
        // Show status
        showStatus_1(*ori);
        showStatus_1(*mcha);
        showStatus_1(*jule);
        std::cout << std::endl;
        // Attack
        mcha->attack("ori");
        ori->takeDamage(mcha->getAttackDamage());
        jule->attack("mcha");
        mcha->takeDamage(jule->getAttackDamage());
        // Show status
        showStatus_1(*ori);
        showStatus_1(*mcha);
        showStatus_1(*jule);
        std::cout << std::endl;
        // Try repair after dead.
        ori->beRepaired(100);
        mcha->beRepaired(10);
        // Show status
        showStatus_1(*ori);
        showStatus_1(*mcha);
        showStatus_1(*jule);
        std::cout << std::endl;

        temp->guardGate();

        delete mcha;
        delete ori;
        delete temp;
        delete jule;
    }
}

int main(void) {
    test();
    // system("leaks ex02");
    return (1);
}