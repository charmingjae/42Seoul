/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:08:46 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 12:45:38 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test00(void) {
    // Create bureaucrat
    Bureaucrat *mcha = new Bureaucrat("mcha", 150);
    std::cout << "[INIT] " << *mcha << std::endl;

    // Create form
    Form *subject = new Form("subject", 149, 150);
    std::cout << "[INIT] " << *subject << std::endl;

    // Can't sign because grade gap
    mcha->signForm(*subject);
    std::cout << *subject << std::endl;

    // Increase grade
    mcha->setIncreGrade();
    std::cout << "[INCREASE] " << *mcha << std::endl;

    // Can sign
    mcha->signForm(*subject);
    std::cout << *subject << std::endl;

    // Can't sign because form already signed
    mcha->signForm(*subject);
    std::cout << *subject << std::endl;

    delete mcha;
    delete subject;
}

void test01(void) {
    // Create bureaucrat
    Bureaucrat *mcha = new Bureaucrat("mcha", 1);
    std::cout << "[INIT - Bureaucrat] " << *mcha << std::endl;

    // Create with copy constructor
    Bureaucrat copy(*mcha);
    std::cout << "[COPY - Bureaucrat] " << copy << std::endl;

    // Decrease copy's grade
    copy.setDecreGrade();
    std::cout << "[DECREASE] " << copy << std::endl;

    // Create form
    Form *form = new Form("math", 130, 140);
    std::cout << "[INIT - Form] " << *form << std::endl;

    // copy can sign at form
    copy.signForm(*form);
    std::cout << *form << std::endl;

    // copy form to fcpy
    Form fcpy(*form);
    std::cout << "[COPY - Form] " << fcpy << std::endl;

    // copy can't sign at fcpy because fcpy is already signed
    copy.signForm(fcpy);
    std::cout << fcpy << std::endl;

    delete mcha;
    delete form;
}

void test02(void) {
    // Create bureaucrat
    Bureaucrat *mcha = new Bureaucrat("mcha", 10);
    std::cout << "[INIT - Bureaucrat] " << *mcha << std::endl;

    Form *form = new Form("exam", 11, 150);
    std::cout << "[INIT - Form] " << *form << std::endl;

    Form cpy(*form);
    std::cout << "[COPY - Form] " << cpy << std::endl;

    mcha->signForm(cpy);
    std::cout << "[COPY - Form status] " << cpy << std::endl;
    std::cout << "[ORIG - Form status] " << *form << std::endl;

    // Additional test
    Form test("test", 10, 150);
    Form cpy2 = test;
    std::cout << "[ASSG - Form] " << cpy2 << std::endl;

    mcha->signForm(test);
    std::cout << "[ORIG - Form] " << test << std::endl;
    std::cout << "[ASSG - Form] " << cpy2 << std::endl;

    delete mcha;
    delete form;
}

int main(void) {
    try {
        std::cout << "\n=========== Scene 01 ===========\n";
        test00();
        std::cout << "\n=========== Scene 02 ===========\n";
        // test01();
        std::cout << "\n=========== Scene 03 ===========\n";
        // test02();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (1);
}