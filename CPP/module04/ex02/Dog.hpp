/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:59:52 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 15:23:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
  private:
    Brain *_brain;

  public:
    Dog();
    Dog(const Dog &paramDog);
    ~Dog();
    Dog &operator=(const Dog &paramDog);

    void makeSound(void) const;
    void setType(std::string paramType);
    std::string getType(void) const;
    Brain *getBrain(void) const;
};

#endif