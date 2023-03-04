/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:50:32 by mcha              #+#    #+#             */
/*   Updated: 2022/07/15 15:27:37 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <class T> void swap(T &a, T &b) {
    T c(a);
    a = b;
    b = c;
}

template <class T> const T &min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

template <class T> const T &max(const T &a, const T &b) {
    return (a < b) ? b : a;
}

#endif