/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:11:45 by mcha              #+#    #+#             */
/*   Updated: 2022/07/05 16:01:20 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = "Hello world!";
    }
    std::cout << "Brain default constructor is executed." << std::endl;
}

Brain::Brain(const Brain &paramBrain) {
    *this = paramBrain;
    std::cout << "Brain copy constructor is executed." << std::endl;
}

Brain::~Brain() { std::cout << "Brain destructor is executed." << std::endl; }

Brain &Brain::operator=(const Brain &paramBrain) {
    for (int i = 0; i < 100; i++) {
        this->setIdeas(i, paramBrain.getIdeas(i));
    }
    std::cout << "Brain operator= is executed." << std::endl;
    return (*this);
}

std::string Brain::getIdeas(int paramIdx) const {
    return (this->_ideas[paramIdx]);
}

void Brain::setIdeas(int paramIdx, std::string paramStr) {
    this->_ideas[paramIdx] = paramStr;
}