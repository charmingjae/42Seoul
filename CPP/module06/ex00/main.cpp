/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:24 by mcha              #+#    #+#             */
/*   Updated: 2022/07/09 23:57:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include "Exception.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2) {
            throw Exception::NotValidArgumentsNumberException();
        }
        Convert convert(av[1]);
        convert.process();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}