/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:46:03 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 15:32:54 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {
  public:
    class NotExistForm : public std::exception {
      public:
        virtual const char *what() const throw();
    };

  public:
    Intern();
    Intern(const Intern &src);
    ~Intern();

    Intern &operator=(const Intern &rhs);

    Form *makeForm(const std::string &paramFormName,
                   const std::string &paramTarget);
};

#endif