/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:27:59 by mcha              #+#    #+#             */
/*   Updated: 2022/07/15 18:44:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T> class Array {
  private:
    size_t _size;
    T *_arr;

  public:
    class OutOfRangeException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  public:
    Array();
    Array(const unsigned int &_n);
    Array(const Array<T> &src);
    Array<T> &operator=(const Array<T> &rhs);
    T &operator[](const unsigned int &idx);
    ~Array();
    size_t size(void);
};

// Construction with no parameter: Creates an empty array.
template <typename T> Array<T>::Array() : _size(0), _arr(new T[0]) {}

// Construction with an unsigned int n as a parameter :
// Creates an array of n elements initialized by default.
template <typename T>
Array<T>::Array(const unsigned int &_n)
    : _size(static_cast<size_t>(_n)), _arr(new T[_n]) {
    for (size_t i = 0; i < _size; i++) {
        this->_arr[i] = 0;
    }
}

// Construction by copy and assignment operator.In both
// cases, modifying either the original array or its copy
// after copying musn’t affect the other array
template <typename T>
Array<T>::Array(const Array<T> &src) : _size(src._size), _arr(NULL) {
    *this = src;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &rhs) {
    this->_size = rhs._size;
    if (this->_arr) {
        delete[] this->_arr;
    }
    this->_arr = new T[this->_size];
    for (size_t i = 0; i < rhs._size; i++) {
        this->_arr[i] = rhs._arr[i];
    }
    return (*this);
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
    return "Array index out of range exception.";
}

// Elements can be accessed through the subscript operator:
// [] When accessing an element with the [ ] operator, if
// its index is out of bounds, an std::exception is thrown.

template <typename T> T &Array<T>::operator[](const unsigned int &idx) {
    if (idx >= this->_size)
        throw Array<T>::OutOfRangeException();
    return this->_arr[idx];
};

// destructor
template <typename T> Array<T>::~Array() {
    if (this->_arr)
        delete[] this->_arr;
}

// function
template <typename T> size_t Array<T>::size(void) { return this->_size; }

#endif