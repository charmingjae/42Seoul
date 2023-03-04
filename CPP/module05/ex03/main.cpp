/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:08:46 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 15:39:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test00(void) {
    Intern someRandomIntern;
    Form *rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *rrf << std::endl;
}

int main(void) {
    try {
        std::cout << "\n=========== Scene 01 ===========\n";
        test00();
        // std::cout << "\n=========== Scene 02 ===========\n";
        // test01();
        // std::cout << "\n=========== Scene 03 ===========\n";
        // test02();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (1);
}