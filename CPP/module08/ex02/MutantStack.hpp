/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:22:00 by mcha              #+#    #+#             */
/*   Updated: 2022/07/18 17:54:07 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {

  public:
    // type definition
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef
        typename std::stack<T>::container_type::const_iterator const_iterator;

    // Orthodox
    MutantStack();
    MutantStack(const MutantStack<T> &src);
    ~MutantStack();
    MutantStack<T> &operator=(const MutantStack<T> &rhs);
    // Function
    iterator begin(void);
    iterator end(void);
    const_iterator cbegin(void) const;
    const_iterator cend(void) const;
};

template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {
    *this = src;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {
    this->c = rhs.c;
    return (*this);
}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const {
    return this->c.cbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const {
    return this->c.cend();
}

#endif