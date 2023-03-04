/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:13:10 by mcha              #+#    #+#             */
/*   Updated: 2022/07/18 00:28:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

void test00(void) {
    std::cout << "\n	Scene 01 - Sequential value\n" << std::endl;
    try {
        // Vector
        std::vector<int> vec;
        // Bind value
        for (int i = 0; i < 10; i++) {
            vec.push_back(i);
        }
        // Print value
        std::cout << "=============== origin ===============\n" << std::endl;

        for (unsigned long i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\n=============== result ===============\n" << std::endl;
        std::vector<int>::iterator res = ::easyfind(vec, 10);
        std::cout << *res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n\n	Scene 02 - Unordered value\n" << std::endl;
    try {
        // Vector
        std::vector<int> vec;
        // Bind value
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(9);
        vec.push_back(7);
        vec.push_back(5);
        // Print value
        std::cout << "=============== origin ===============\n" << std::endl;

        for (unsigned long i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\n=============== result ===============\n" << std::endl;
        std::vector<int>::iterator res = ::easyfind(vec, 9);
        std::cout << *res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void test01(void) {
    std::cout << "\n	Scene 01 - Sequential value\n" << std::endl;
    try {
        std::deque<int> deq;
        // Bind value
        for (int i = 0; i < 10; i++) {
            deq.push_back(i);
        }
        // Print value
        std::cout << "=============== origin ===============\n" << std::endl;

        for (unsigned long i = 0; i < deq.size(); i++) {
            std::cout << deq[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\n=============== result ===============\n" << std::endl;
        std::deque<int>::iterator res = ::easyfind(deq, 10);
        std::cout << *res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n\n	Scene 02 - Unordered value\n" << std::endl;
    try {
        // Deque
        std::deque<int> deq;
        // Bind value
        deq.push_back(3);
        deq.push_back(1);
        deq.push_back(9);
        deq.push_back(7);
        deq.push_back(5);
        // Print value
        std::cout << "=============== origin ===============\n" << std::endl;

        for (unsigned long i = 0; i < deq.size(); i++) {
            std::cout << deq[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\n=============== result ===============\n" << std::endl;
        std::deque<int>::iterator res = ::easyfind(deq, 9);
        std::cout << *res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void test02(void) {
    std::cout << "\n	Scene 01 - Sequential value\n" << std::endl;
    try {
        std::list<int> lst;
        // Bind value
        for (int i = 0; i < 10; i++) {
            lst.push_back(i);
        }
        std::cout << "\n=============== result ===============\n" << std::endl;
        std::list<int>::iterator res = ::easyfind(lst, 10);
        std::cout << *res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n\n	Scene 02 - Unordered value\n" << std::endl;
    try {
        // List
        std::list<int> lst;
        // Bind value
        lst.push_back(3);
        lst.push_back(1);
        lst.push_back(9);
        lst.push_back(7);
        lst.push_back(5);
        std::cout << "\n=============== result ===============\n" << std::endl;
        std::list<int>::iterator res = ::easyfind(lst, 9);
        std::cout << *res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void test03(void) {
    try {
        std::set<int> st;
        st.insert(1);
        st.insert(5);
        st.insert(3);
        st.insert(9);
        st.insert(7);

        std::set<int>::iterator it = ::easyfind(st, 5);
        std::cout << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void) {
    // Vector
    test00();
    // Deque
    // test01();
    // List
    // test02();
    // Set
    // test03();
    return (0);
}