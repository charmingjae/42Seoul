/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AboutFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:40:48 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 19:50:59 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AboutFile.hpp"

std::string AboutFile::getResult(void) { return _result; }
void AboutFile::addString(std::string paramStr) { _result += paramStr; }