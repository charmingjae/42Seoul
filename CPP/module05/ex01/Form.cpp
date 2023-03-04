/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:40:23 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 12:44:59 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signed(false), _signGrade(150), _executeGrade(150) {
    if (this->_signGrade > 150 || this->_executeGrade > 150)
        throw Form::GradeTooLowException();
    else if (this->_signGrade < 1 || this->_executeGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &src)
    : _name(src._name), _signGrade(src._signGrade),
      _executeGrade(src._executeGrade) {
    *this = src;
}

Form::Form(const std::string &paramName, const int paramSignGrade,
           const int paramExecuteGrade)
    : _name(paramName), _signed(false), _signGrade(paramSignGrade),
      _executeGrade(paramExecuteGrade) {
    if (this->_signGrade > 150 || this->_executeGrade > 150)
        throw Form::GradeTooLowException();
    else if (this->_signGrade < 1 || this->_executeGrade < 1)
        throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &rhs) {
    if (rhs.getSignGrade() > 150 || rhs.getExecuteGrade() > 150)
        throw Form::GradeTooLowException();
    else if (rhs.getSignGrade() < 1 || rhs.getExecuteGrade() < 1)
        throw Form::GradeTooHighException();
    this->_signed = rhs.getSigned();
    return (*this);
}

Form::~Form() {}

std::string Form::getName(void) const { return this->_name; }

bool Form::getSigned(void) const { return this->_signed; }

int Form::getSignGrade(void) const { return this->_signGrade; }

int Form::getExecuteGrade(void) const { return this->_executeGrade; }

bool Form::beSigned(const Bureaucrat &src) {
    // check this range
    if (this->_signGrade > 150 || this->_executeGrade > 150)
        throw Form::GradeTooLowException();
    else if (this->_signGrade < 1 || this->_executeGrade < 1)
        throw Form::GradeTooHighException();
    // check src range
    if (src.getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (src.getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    // Compare grade and do sign
    if (this->getSignGrade() >= src.getGrade()) {
        if (this->getSigned() == true) {
            throw Form::FormAlreadySignedException();
            return false;
        } else {
            this->_signed = true;
            return true;
        }
    } else if (this->getSignGrade() < src.getGrade()) {
        throw Form::AuthGapIsTooBigException();
        return false;
    }
    throw Form::UnknownException();
    return false;
}

// Exception
const char *Form::GradeTooHighException::what() const throw() {
    return "[Exception - Form] Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "[Exception - Form] Grade is too low.";
}

const char *Form::FormAlreadySignedException::what() const throw() {
    return "Form already signed.";
}

const char *Form::AuthGapIsTooBigException::what() const throw() {
    return "didn't have enough grade";
}

const char *Form::UnknownException::what() const throw() {
    return "Unknown reason.";
}

std::ostream &operator<<(std::ostream &os, const Form &src) {
    os << src.getName() << ", form signed " << src.getSigned()
       << " , signGrade " << src.getSignGrade() << " , executeGrade "
       << src.getExecuteGrade() << std::endl;
    return (os);
}