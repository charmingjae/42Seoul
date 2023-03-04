/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:24:45 by mcha              #+#    #+#             */
/*   Updated: 2022/06/22 21:08:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    // Heap
    Zombie *zombieMcha = newZombie("mcha");
    zombieMcha->announce();

    // Stack
    randomChump("jule");
    randomChump("ghan");
    randomChump("yeji");

    // Stack
    Zombie zombieYongjule("jiskim");
    zombieYongjule.announce();

    // Destroy
    delete zombieMcha;
}