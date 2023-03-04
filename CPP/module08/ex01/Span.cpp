/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:24:23 by mcha              #+#    #+#             */
/*   Updated: 2022/07/18 16:09:05 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(0), _vec() {}

Span::Span(unsigned int n) : _capacity(n), _vec() {}

Span::Span(const Span &src) : _capacity(src._capacity), _vec() { *this = src; }

Span &Span::operator=(const Span &rhs) {
    this->_vec.clear();
    this->_capacity = rhs._capacity;
    this->_vec = rhs._vec;
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int paramNbr) {
    if (this->_vec.size() >= this->_capacity) {
        throw Span::CannotAddNumberException();
    }
    this->_vec.push_back(paramNbr);
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
    if (static_cast<unsigned long>(end - begin) >
        this->_capacity - this->_vec.size()) {
        throw Span::CannotAddNumberException();
    }
    _vec.insert(_vec.end(), begin, end);
}

unsigned int Span::getCapacity(void) { return this->_capacity; }

void Span::printVectorArguments(void) {
    std::vector<int>::iterator IT;

    for (IT = this->_vec.begin(); IT != this->_vec.end(); IT++) {
        std::cout << *IT << std::endl;
    }
}

int Span::shortestSpan(void) {
    if (this->_vec.size() == 0 || this->_vec.size() == 1) {
        throw Span::CannotFindSpanException();
    }

    int gap = 2147483647;
    std::sort(this->_vec.begin(), this->_vec.end());
    std::vector<int>::iterator vecIT;
    for (vecIT = this->_vec.begin(); vecIT != this->_vec.end() - 1; vecIT++) {
        gap = (gap < std::abs(*(vecIT + 1) - *vecIT))
                  ? gap
                  : std::abs(*(vecIT + 1) - *vecIT);
    }
    return (gap);
}

int Span::longestSpan(void) {
    if (this->_vec.size() == 0 || this->_vec.size() == 1) {
        throw Span::CannotFindSpanException();
    }
    std::sort(this->_vec.begin(), this->_vec.end());
    int gap = this->_vec.back() - this->_vec.front();
    return (gap);
}

// Exception
const char *Span::CannotAddNumberException::what() const throw() {
    return "Cannot add more number";
}

const char *Span::CannotFindSpanException::what() const throw() {
    return "Cannot find span";
}