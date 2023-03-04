/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:28 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 19:00:49 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
  private:
    std::string _name;
    Weapon *_weapon;

  public:
    HumanB(std::string paramName);
    ~HumanB();
    void attack(void);
    void setWeapon(Weapon &paramWeapon);
};

#endif