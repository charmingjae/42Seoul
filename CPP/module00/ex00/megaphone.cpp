/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:48:32 by mcha              #+#    #+#             */
/*   Updated: 2022/06/22 15:47:47 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

void convertToUpperCase(const char *str) {
    while (*str) {
        std::cout << static_cast<char>(std::toupper(*str));
        str++;
    }
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    } else {
        for (int i = 1; i < ac; i++) {
            convertToUpperCase(av[i]);
        }
        std::cout << std::endl;
        return (0);
    }
}