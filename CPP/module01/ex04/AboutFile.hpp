/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AboutFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:40:54 by mcha              #+#    #+#             */
/*   Updated: 2022/06/23 19:49:51 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABOUTFILE_HPP
#define ABOUTFILE_HPP

#include <string>

class AboutFile {
  private:
    std::string _result;

  public:
    std::string getResult(void);
    void addString(std::string paramStr);
};

#endif