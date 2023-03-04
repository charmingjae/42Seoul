/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:23:43 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 22:43:00 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(const AMateria &paramAMateria);
    AMateria(std::string const &type);
    virtual ~AMateria();

    AMateria &operator=(const AMateria &paramAMateria);

    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif