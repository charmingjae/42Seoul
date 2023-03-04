/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:35:59 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 17:41:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
  public:
    Cure();
    Cure(const Cure &paramCure);
    ~Cure();

    Cure &operator=(const Cure &paramCure);
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif