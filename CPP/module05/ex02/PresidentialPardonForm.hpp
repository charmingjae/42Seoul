/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:06:38 by mcha              #+#    #+#             */
/*   Updated: 2022/07/08 14:09:32 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
  private:
    std::string _target;

  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm(const std::string &paramTarget);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    void execute(Bureaucrat const &executor) const;

    std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &src);

#endif