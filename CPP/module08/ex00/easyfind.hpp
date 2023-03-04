/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:07:41 by mcha              #+#    #+#             */
/*   Updated: 2022/07/18 17:17:50 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &first, const int &val) {
    typedef typename T::iterator ITER;

    ITER result = std::find(first.begin(), first.end(), val);
    if (result == first.end()) {
        // throw exception
        throw std::invalid_argument("Invalid argument");
    }
    return result;
}

#endif