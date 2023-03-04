/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:18 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 21:24:22 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string paramFstName, std::string paramLstName,
                 std::string paramNickName, std::string paramPhnNbr,
                 std::string paramDkstSecret)
    : _firstName(paramFstName), _lastName(paramLstName),
      _nickName(paramNickName), _phoneNumber(paramPhnNbr),
      _darkestSecret(paramDkstSecret) {}

std::string Contact::getFirstName(void) { return _firstName; }
std::string Contact::getLastName(void) { return _lastName; }
std::string Contact::getNickName(void) { return _nickName; }
std::string Contact::getPhoneNumber(void) { return _phoneNumber; }
std::string Contact::getDarkestSecret(void) { return _darkestSecret; }