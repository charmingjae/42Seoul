/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:17:09 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 21:54:40 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    AMateria **_slot;

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &paramMs);
    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &paramMs);

    void learnMateria(AMateria *paramMateria);
    AMateria *createMateria(std::string const &type);
};

#endif