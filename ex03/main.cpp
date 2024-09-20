/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:35:05 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/20 18:35:05 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "-----------------------" << std:: endl;
	std::cout << "   Test from subject   " << std:: endl;
	std::cout << "-----------------------" << std:: endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	// delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "-----------------------" << std:: endl;
	std::cout << " Test inventory/storage" << std:: endl;
	std::cout << "-----------------------" << std:: endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(1);

	std::cout << "-----------------------" << std:: endl;
	std::cout << "(Me) Inventory slot 0: " << me->getInventory(0) << std::endl;
	std::cout << "(Me) Inventory slot 1: " << me->getInventory(1) << std::endl;
	std::cout << "(Me) Inventory slot 2: " << me->getInventory(2) << std::endl;
	std::cout << "(Me) Inventory slot 3: " << me->getInventory(3) << std::endl;
	std::cout << "(Me) Storage slot 0:   " << me->getStorage(0) << std::endl;
	std::cout << "-----------------------" << std:: endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "-----------------------" << std:: endl;
	std::cout << "(Me) Inventory slot 0: " << me->getInventory(0) << std::endl;
	std::cout << "(Me) Inventory slot 1: " << me->getInventory(1) << std::endl;
	std::cout << "(Me) Inventory slot 2: " << me->getInventory(2) << std::endl;
	std::cout << "(Me) Inventory slot 3: " << me->getInventory(3) << std::endl;
	std::cout << "-----------------------" << std:: endl;
	std::cout << std::endl;
	std::cout << "-----------------------" << std:: endl;
	std::cout << "  Test copy character  " << std:: endl;
	std::cout << "-----------------------" << std:: endl;

	ICharacter* me2 = me;
	std::cout << "(Me2) Inventory slot 0: " << me2->getInventory(0) << std::endl;
	std::cout << "(Me2) Inventory slot 1: " << me2->getInventory(1) << std::endl;
	std::cout << "(Me2) Inventory slot 2: " << me2->getInventory(2) << std::endl;
	std::cout << "(Me2) Inventory slot 3: " << me2->getInventory(3) << std::endl;
	std::cout << "(Me2) Storage slot 0:   " << me2->getStorage(0) << std::endl;
	std::cout << "-----------------------" << std:: endl;

	delete bob;
	delete me;
	delete src;
	return 0;
}

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     for (int i = 0; i < 4; ++i)
//     {
//         AMateria* tmp = src->createMateria("ice");
//         me->equip(tmp);
// 		delete tmp;
//     }
//     AMateria* unknown = src->createMateria("unknown");
//     if (unknown == NULL)
//         std::cout << "Unknown Materia type not created" << std::endl;
//     MateriaSource* src2 = new MateriaSource();
//     for (int i = 0; i < 5; ++i)
//     {
//         if (i < 4)
//         {
//             src2->learnMateria(new Cure());
// 			// delete src2;
//             std::cout << "Materia nr.: " << i + 1 << " learned " << std::endl;
//         }
//         else
//             std::cout << "Maximum limit of learned Materias reached." << std::endl;
//     }
//     delete src;
//     delete me;
//     delete src2;
//     return 0;
// }
