/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputView.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:35:26 by mcha              #+#    #+#             */
/*   Updated: 2022/06/21 19:49:35 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTVIEW_HPP
#define INPUTVIEW_HPP

#include "OutputView.hpp"
#include <cctype>
#include <iostream>

class InputView {
  public:
    InputView();
    int checkDigit(std::string paramString);
    int enterCommand(std::string &paramCommand);
    int enterSearchIndex(std::string &paramInput);
    int checkContactComponentValid(std::string paramInput);
    int enterContactComponent(std::string (&paramInput)[5]);
    void getInputTheme(OutputView paramOutputView, int paramIndex);
};

#endif