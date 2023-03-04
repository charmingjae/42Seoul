/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:00:36 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 15:22:48 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  private:
    Brain *_brain;

  public:
    Cat();
    Cat(const Cat &paramCat);
    ~Cat();
    Cat &operator=(const Cat &paramCat);

    void makeSound(void) const;
    void setType(std::string paramType);
    std::string getType(void) const;
    Brain *getBrain(void) const;
};

#endif