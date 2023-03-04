/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:15:39 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 13:30:49 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;

#define ASCII_TREE                                                             \
    "         ccee88oo\n\
  C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP\n\
      \\\\\\//  /douUP\n\
        \\\\\\////\n\
         |||/\\\n\
         |||\\/\n\
         |||||\n\
   .....//||||\\...."

class ShrubberyCreationForm : public Form {
  private:
    std::string _target;

  public:
    class FileException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ShrubberyCreationForm(const std::string &paramTarget);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    void execute(Bureaucrat const &executor) const;

    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &src);

#endif