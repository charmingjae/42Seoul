/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:47:46 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 17:43:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
  public:
    // Exception class
    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  private:
    const std::string _name;
    int _grade; // 1 to 150

  public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat(const std::string &paramName, int paramGrade);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &rhs);

    std::string getName(void) const;
    int getGrade(void) const;
    void setIncreGrade(void);
    void setDecreGrade(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif