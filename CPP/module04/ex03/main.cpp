/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:45:07 by mcha              #+#    #+#             */
/*   Updated: 2022/07/06 12:31:30 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void test01(void) {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

void test02(void) {
    IMateriaSource *src = new MateriaSource();
    // Store more than 4 skills
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    // Character
    ICharacter *jule = new Character("jule");
    Character *mcha = new Character("mcha");
    std::cout << "Jule's name : " << jule->getName() << std::endl;
    std::cout << "Mcha's name : " << mcha->getName() << std::endl;

    // Create materia and equip more than 4
    AMateria *mat;
    mat = src->createMateria("ice");
    std::cout << "mat's type : " << mat->getType() << std::endl;
    mcha->equip(mat);
    mat = src->createMateria("cure");
    std::cout << "mat's type : " << mat->getType() << std::endl;
    mcha->equip(mat);
    mat = src->createMateria("ice");
    mcha->equip(mat);
    mat = src->createMateria("ice");
    mcha->equip(mat);
    mat = src->createMateria("ice");
    mcha->equip(mat);
    mat = src->createMateria("cure");
    mcha->equip(mat);
    mat = src->createMateria("ice");
    mcha->equip(mat);
    mat = src->createMateria("cure");
    mcha->equip(mat);
    mat = src->createMateria("ice");
    mcha->equip(mat);
    mat = src->createMateria("cure");
    mcha->equip(mat);
    mat = src->createMateria("ice");
    mcha->equip(mat);

    // use
    for (int i = 0; i < 100; i++) {
        mcha->use(i, *jule);
    }

    delete mcha;
    delete jule;
    delete src;
}

int main() {
    std::cout << "\n=========================== Scene 01 "
                 "===========================\n";
    test01();
    std::cout << "\n=========================== Scene 02 "
                 "===========================\n";
    test02();
    std::cout << std::endl;
    // system("leaks ex03");
    return 0;
}