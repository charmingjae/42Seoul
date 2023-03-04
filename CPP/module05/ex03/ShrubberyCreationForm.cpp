/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:16:39 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 14:22:40 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", 145, 137), _target("unknown") {
    std::cout << "ShrubberyCreationForm default constructor is executed."
              << std::endl;
}

// Should I copy 'signed' member attribute?
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : Form("ShrubberyCreationForm", 145, 137), _target(src._target) {
    *this = src;
    std::cout << "ShrubberyCreationForm copy constructor is executed."
              << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &paramTarget)
    : Form("ShrubberyCreationForm", 145, 137), _target(paramTarget) {
    std::cout << "ShrubberyCreationForm constructor with target is executed."
              << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    this->_target = rhs._target;
    std::cout << "ShrubberyCreationForm operator= is executed." << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor is executed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    // 01. Check auth of executor and is form signed.
    if (this->getExecuteGrade() < executor.getGrade()) {
        throw Form::AuthGapIsTooBigException();
    } else if (!this->getSigned()) {
        throw Form::FormNotSignedException();
    }
    // 02. make file and writes ASCII trees inside it.
    std::ofstream file(this->getTarget() + "_shrubbery");
    if (file.is_open()) {
        file << ASCII_TREE;
    } else {
        throw ShrubberyCreationForm::FileException();
    }
}

std::string ShrubberyCreationForm::getTarget(void) const {
    return this->_target;
}

// Exception

const char *ShrubberyCreationForm::FileException::what() const throw() {
    return "file not opened";
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &src) {
    os << src.getName() << ", form signed " << src.getSigned()
       << " , signGrade " << src.getSignGrade() << " , executeGrade "
       << src.getExecuteGrade() << " , target " << src.getTarget() << std::endl;
    return (os);
}