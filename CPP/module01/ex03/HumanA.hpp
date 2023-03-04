/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:54:57 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 14:23:11 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
  private:
    std::string _name;
    Weapon &_weapon;

  public:
    HumanA(std::string paramName, Weapon &paramWeapon);
    ~HumanA();
    void attack(void);
};

#endif