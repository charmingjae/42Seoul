/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:26:13 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 14:02:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public Form {
  private:
    std::string _target;

  public:
    class RobotomyFailException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm(const std::string &paramTarget);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    void execute(Bureaucrat const &executor) const;

    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &src);

#endif