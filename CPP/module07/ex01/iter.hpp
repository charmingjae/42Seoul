/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:23:56 by mcha              #+#    #+#             */
/*   Updated: 2022/07/15 15:38:43 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class T> void func(const T &parameter) {
    std::cout << parameter << " ";
}

template <class T>
void iter(const T *addr, const size_t &size, void (*_func)(const T &)) {
    for (size_t i = 0; i < size; i++) {
        _func(addr[i]);
    }
}

#endif