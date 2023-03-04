/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:24:36 by mcha              #+#    #+#             */
/*   Updated: 2022/07/18 16:08:00 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void given(void) {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void my(void) {
    try {
        Span test = Span(8);
        test.addNumber(9);
        test.addNumber(9);
        test.addNumber(9);
        test.addNumber(9);

        // test.printVectorArguments();
        std::vector<int> nbr;

        nbr.push_back(-1);
        nbr.push_back(1);
        nbr.push_back(2);
        nbr.push_back(3);
        test.addNumber(nbr.begin(), nbr.end());

        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void additional(void) {
    try {
        Span additional = Span(10);

        std::vector<int> vec;
        for (int i = 0; i < 9999; i++) {
            vec.push_back(i);
        }
        vec.push_back(-1);
        additional.addNumber(vec.begin(), vec.end());
        // additional.printVectorArguments();
        std::cout << additional.shortestSpan() << std::endl;
        std::cout << additional.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void) {
    std::cout << "\n============== Given ==============\n" << std::endl;
    given();
    std::cout << "\n============== Mytst ==============\n" << std::endl;
    // my();
    std::cout << "\n============== 10,000 =============\n" << std::endl;
    // additional();
    // system("leaks ex01");
    return (0);
}