/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:59:52 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 00:31:20 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &paramDog);
    ~Dog();
    Dog &operator=(const Dog &paramDog);

    void makeSound(void) const;
};

#endif