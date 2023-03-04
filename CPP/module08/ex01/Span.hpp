/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:06:12 by mcha              #+#    #+#             */
/*   Updated: 2022/07/18 16:31:37 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <climits>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

class Span {
  private:
    unsigned int _capacity;
    std::vector<int> _vec;

  public:
    class CannotAddNumberException : public std::exception {
        virtual const char *what() const throw();
    };

    class CannotFindSpanException : public std::exception {
        virtual const char *what() const throw();
    };

  public:
    // Orthodox
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &rhs);

    // Function
    void addNumber(int paramNbr);
    void addNumber(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end);
    int shortestSpan(void);
    int longestSpan(void);
    unsigned int getCapacity(void);
    void printVectorArguments(void);
};

#endif