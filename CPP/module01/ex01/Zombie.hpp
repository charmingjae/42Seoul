/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:12:08 by mcha              #+#    #+#             */
/*   Updated: 2022/06/22 21:42:01 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string paramName);
    std::string getName(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif