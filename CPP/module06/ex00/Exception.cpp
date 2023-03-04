/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:30:32 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 22:31:27 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

const char *Exception::NotValidArgumentsNumberException::what() const throw() {
    return "[Exception] Invalid arguments number";
}