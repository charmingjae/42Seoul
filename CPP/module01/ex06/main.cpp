/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:57:56 by mcha              #+#    #+#             */
/*   Updated: 2022/06/24 15:07:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error.. please enter one level" << std::endl;
        return (0);
    }
    Harl harl;

    harl.complain(av[1]);
    return (1);
}