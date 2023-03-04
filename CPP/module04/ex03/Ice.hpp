/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:37:45 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 17:40:57 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
  public:
    Ice();
    Ice(const Ice &paramIce);
    ~Ice();

    Ice &operator=(const Ice &paramIce);
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif