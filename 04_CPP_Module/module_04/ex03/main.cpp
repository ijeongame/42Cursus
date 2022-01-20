/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:08:18 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/19 00:28:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	std::cout << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}
// int main()
// {
//   IMateriaSource* src = new MateriaSource();
//   src->learnMateria(new Ice());
//   src->learnMateria(new Ice());
//   src->learnMateria(NULL);
//   src->learnMateria(new Cure());
//   src->learnMateria(new Cure());

//   AMateria* tmp;
//   tmp = src->createMateria("icecure");

//   ICharacter* me = new Character("me");
//   ICharacter* bob = new  Character("bob");

//   tmp = src->createMateria("ice");
//   me->equip(tmp);
//   tmp = src->createMateria("cure");
//   me->equip(tmp);

//   AMateria* tmp1 = src->createMateria("ice");
//   me->equip(tmp1);
//   AMateria* tmp2 = src->createMateria("cure");
//   me->equip(tmp);

//   me->unequip(2);
//   me->unequip(3);

//   bob->equip(tmp1);
//   bob->equip(tmp2);

//   me->use(0, *bob);
//   me->use(1, *bob);

//   bob->use(0, *me);
//   bob->use(1, *me);

//   delete bob;
//   delete me;
//   delete src;
// }
