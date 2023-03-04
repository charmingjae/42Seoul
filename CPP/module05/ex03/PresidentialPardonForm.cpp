/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:08:07 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 14:13:50 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("PresidentialPardonForm", 25, 5), _target("unknown") {
    std::cout << "PresidentialPardonForm default constructor is executed."
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : Form("PresidentialPardonForm", 25, 5), _target(src._target) {
    std::cout << "PresidentialPardonForm copy constructor is executed."
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &paramTarget)
    : Form("PresidentialPardonForm", 25, 5), _target(paramTarget) {
    std::cout << "PresidentialPardonForm constructor with target is executed."
              << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    this->_target = rhs._target;
    std::cout << "PresidentialPardonForm operator= is executed." << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor is executed." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    // 01. Check auth of executor and is form signed.
    if (this->getExecuteGrade() < executor.getGrade()) {
        throw Form::AuthGapIsTooBigException();
    } else if (!this->getSigned()) {
        throw Form::FormNotSignedException();
    }
    // 02. Informs that <target> has been pardoned by Zaphod Beeblebrox
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {
    return this->_target;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &src) {
    os << src.getName() << ", form signed " << src.getSigned()
       << " , signGrade " << src.getSignGrade() << " , executeGrade "
       << src.getExecuteGrade() << " , target " << src.getTarget() << std::endl;
    return (os);
}
