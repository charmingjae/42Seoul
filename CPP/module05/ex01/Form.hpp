/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:17:43 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 12:43:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _executeGrade;

  public:
    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class AuthGapIsTooBigException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class UnknownException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  public:
    Form();
    Form(const Form &src);
    Form(const std::string &paramName, const int paramSignGrade,
         const int paramExecuteGrade);
    ~Form();

    Form &operator=(const Form &rhs);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;
    bool beSigned(const Bureaucrat &src);
};

std::ostream &operator<<(std::ostream &os, const Form &src);
#endif