/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:00:36 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 15:31:32 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { *this = src; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return (*this);
}

Form *Intern::makeForm(const std::string &paramFormName,
                       const std::string &paramTarget) {
    std::string _form[3] = {"shrubbery creation", "robotomy request",
                            "presidential pardon"};
    int idx = 0;
    while (idx < 3 && _form[idx] != paramFormName) {
        idx++;
    }
    switch (idx) {
    case 0:
        return new ShrubberyCreationForm(paramTarget);
    case 1:
        return new RobotomyRequestForm(paramTarget);
    case 2:
        return new PresidentialPardonForm(paramTarget);
    }
    std::cout << "idx : " << idx << std::endl;
    throw Intern::NotExistForm();
}

const char *Intern::NotExistForm::what() const throw() {
    return "no match form";
}
