/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:36:21 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 14:38:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
  private:
    std::string _type;

  public:
    Weapon();
    Weapon(std::string paramType);
    ~Weapon();
    const std::string &getType(void) const;
    void setType(const std::string &paramType);
};

#endif