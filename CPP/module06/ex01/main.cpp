/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:02:05 by mcha              #+#    #+#             */
/*   Updated: 2022/07/14 14:51:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

void proc(void) {
    Data *data = new Data();
    data->setValue(100);

    std::cout << "Original address : " << data << std::endl;
    std::cout << "Original values : " << data->getValue() << std::endl;

    uintptr_t serialized = serialize(data);
    std::cout << "\nSerialized address : " << std::hex << serialized << std::dec
              << std::endl;

    Data *conv = deserialize(serialized);

    std::cout << "\nDeserialized address : " << conv << std::endl;
    std::cout << "Deserialized values : " << conv->getValue() << std::endl;

    std::cout << "=======================================" << std::endl;
    if (data == conv) {
        std::cout << "Original and Deserialized object is same" << std::endl;
        std::cout << "Original address : " << data << std::endl;
        std::cout << "Original value : " << data->getValue() << std::endl;
        std::cout << "Deserialized address : " << conv << std::endl;
        std::cout << "Deserialized value : " << conv->getValue() << std::endl;
    }
    delete data;
}

int main(void) {
    proc();
    // system("leaks serialization");
    return (0);
}