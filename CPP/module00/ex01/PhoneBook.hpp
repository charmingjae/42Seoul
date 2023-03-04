/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:31:09 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 20:43:44 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
  private:
    int _idx;
    Contact _phoneBook[8];

  public:
    PhoneBook();
    int getNowIndex(void);
    void increaseIndex(void);
    Contact *getAllContact(void);
    Contact getSpecContact(int paramIdx);
    int addNewContact(Contact paramContact);
};

#endif