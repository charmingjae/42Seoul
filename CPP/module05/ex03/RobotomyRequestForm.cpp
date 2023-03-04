/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:29:53 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 14:44:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequestForm", 72, 45), _target("unknown") {
    std::cout << "RobotomyRequestForm default constructor is executed."
              << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : Form("RobotomyRequestForm", 72, 45), _target(src._target) {
    *this = src;
    std::cout << "RobotomyRequestForm copy constructor is executed."
              << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &paramTarget)
    : Form("RobotomyRequestForm", 72, 45), _target(paramTarget) {
    std::cout << "RobotomyRequestForm constructor with target is executed."
              << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    this->_target = rhs._target;
    std::cout << "RobotomyRequestForm operator= is executed." << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor is executed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    // 01. Check auth of executor and is form signed.
    if (this->getExecuteGrade() < executor.getGrade()) {
        throw Form::AuthGapIsTooBigException();
    } else if (!this->getSigned()) {
        throw Form::FormNotSignedException();
    }
    // 02. Makes some drilling noises. Then, informs that <target> has been
    // robotomized successfully 50 % of the time.Otherwise, informs that the
    // robotomy failed.
    std::cout << " B-BEEP... BEEP-B... B-B-BEEEP..." << std::endl;
    std::srand(5323);
    if (rand() % 2) {
        std::cout << this->getTarget() << " has been robotomized successfully"
                  << std::endl;
    } else {
        throw RobotomyRequestForm::RobotomyFailException();
    }
}

std::string RobotomyRequestForm::getTarget(void) const { return this->_target; }

const char *RobotomyRequestForm::RobotomyFailException::what() const throw() {
    return "Robotomy failed";
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &src) {
    os << src.getName() << ", form signed " << src.getSigned()
       << " , signGrade " << src.getSignGrade() << " , executeGrade "
       << src.getExecuteGrade() << " , target " << src.getTarget() << std::endl;
    return (os);
}