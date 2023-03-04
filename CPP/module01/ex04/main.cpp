/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:09:38 by mcha              #+#    #+#             */
/*   Updated: 2022/06/24 14:09:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Controller.hpp"

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << "[Error] parameter count is not 4" << std::endl;
        return (0);
    }
    Controller controller;
    if (controller.proc(av[1], av[2], av[3]))
        return (0);
    return (1);
}