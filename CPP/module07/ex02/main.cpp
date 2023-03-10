/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:39:18 by mcha              #+#    #+#             */
/*   Updated: 2022/07/15 18:43:33 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750

int proc(void) {
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return (0);
}

int main(int, char **) {
    if (proc())
        return (1);
    // system("leaks ex02");
    return 0;
}