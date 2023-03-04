/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:30:30 by mcha              #+#    #+#             */
/*   Updated: 2022/07/15 18:40:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstdlib>
#include <ctime>

int getRandomNumber(void) {
    static bool check = true;
    if (check) {
        std::srand(std::time(NULL));
        check = false;
    }
    int random_variable = std::rand();
    return random_variable % 100;
}

void proc(void) {
    // int array
    int *arr00 = new int[30];
    for (int i = 0; i < 30; i++) {
        arr00[i] = getRandomNumber();
    }
    std::cout << "Original	:	";
    for (int i = 0; i < 30; i++) {
        std::cout << arr00[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Result		:	";
    // iter
    ::iter(arr00, 30, func);
    std::cout << std::endl;
    delete[] arr00;
}

int main(void) {
    proc();
    // system("leaks ex01");
    return (0);
}