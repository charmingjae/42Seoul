/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:53:04 by mcha              #+#    #+#             */
/*   Updated: 2022/07/14 14:38:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data {
  private:
    int _value;

  public:
    Data();
    Data(const Data &src);
    ~Data();

    Data &operator=(const Data &rhs);

    int getValue(void);
    void setValue(int param);
};

#endif