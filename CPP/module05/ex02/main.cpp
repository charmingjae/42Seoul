/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:08:46 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 14:44:46 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test00(void) {
    Bureaucrat mcha("mcha", 72);
    std::cout << "[INIT - Bureaucrat] " << mcha << std::endl;

    ShrubberyCreationForm *robot = new ShrubberyCreationForm("ghan");
    std::cout << "[INIT - Shrubbery] " << *robot << std::endl;

    mcha.executeForm(*robot);
    std::cout << *robot << std::endl;

    mcha.signForm(*robot);
    std::cout << *robot << std::endl;

    mcha.executeForm(*robot);
    std::cout << *robot << std::endl;

    ShrubberyCreationForm copy00 = *robot;
    std::cout << "[ASSG - Shrubbery] " << copy00 << std::endl;

    mcha.executeForm(copy00);
    std::cout << copy00 << std::endl;

    mcha.signForm(copy00);
    std::cout << copy00 << std::endl;

    mcha.executeForm(copy00);
    std::cout << copy00 << std::endl;
}

void test01(void) {
    Bureaucrat mcha("mcha", 72);
    std::cout << "[INIT - Bureaucrat] " << mcha << std::endl;

    RobotomyRequestForm *robot = new RobotomyRequestForm("jiskim");
    std::cout << "[INIT - Robotomy] " << *robot << std::endl;

    mcha.executeForm(*robot);
    std::cout << *robot << std::endl;

    mcha.signForm(*robot);
    std::cout << *robot << std::endl;

    mcha.executeForm(*robot);
    std::cout << *robot << std::endl;

    RobotomyRequestForm copy00 = *robot;
    std::cout << "[ASSG - Robotomy] " << copy00 << std::endl;

    mcha.executeForm(copy00);
    std::cout << copy00 << std::endl;

    mcha.signForm(copy00);
    std::cout << copy00 << std::endl;

    mcha.executeForm(copy00);
    std::cout << copy00 << std::endl;
}

void test02(void) {
    Bureaucrat *mcha = new Bureaucrat("mcha", 4);
    std::cout << "[INIT - Bureaucrat] " << *mcha << std::endl;

    PresidentialPardonForm *pres = new PresidentialPardonForm("jule");
    std::cout << "[INIT - Presidential] " << *pres << std::endl;

    mcha->signForm(*pres);
    std::cout << *pres << std::endl;

    PresidentialPardonForm copy00(*pres);
    std::cout << "[COPY - Presidential] " << copy00 << std::endl;

    mcha->executeForm(copy00);
    std::cout << copy00 << std::endl;

    mcha->signForm(copy00);
    std::cout << copy00 << std::endl;

    mcha->executeForm(copy00);
    std::cout << copy00 << std::endl;
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