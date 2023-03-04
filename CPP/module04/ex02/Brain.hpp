/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:01:22 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 16:01:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
  private:
    std::string _ideas[100];

  public:
    Brain();
    Brain(const Brain &paramBrain);
    ~Brain();
    Brain &operator=(const Brain &paramBrain);

    std::string getIdeas(int paramIdx) const;
    void setIdeas(int paramIdx, std::string paramStr);
};

#endif