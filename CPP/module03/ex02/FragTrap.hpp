/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:28:09 by mcha              #+#    #+#             */
/*   Updated: 2022/07/03 23:43:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    FragTrap();
    FragTrap(const std::string &paramName);
    FragTrap(const FragTrap &fragTrap);
    ~FragTrap();

    // Operator
    FragTrap &operator=(const FragTrap &fragTrap);

    // Function
    void highFivesGuys(void);
};

#endif