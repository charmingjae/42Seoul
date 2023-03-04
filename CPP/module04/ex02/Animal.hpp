/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:58:25 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 16:09:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
  protected:
    std::string _type;

  public:
    Animal();
    Animal(const Animal &paramAnimal);
    virtual ~Animal();
    Animal &operator=(const Animal &paramAnimal);

    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
};

#endif