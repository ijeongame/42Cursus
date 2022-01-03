/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:36:48 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 17:43:35 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 19:59:51 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name){
	this->name = name;
	weapon = NULL;
}

void HumanB::attack(){
<<<<<<< HEAD
	std::cout << name << "attacks with is" << weapon->getType() << std::endl;
=======
	std::cout << name << " attacks with is " << weapon->getType() << std::endl;
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
}

void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

HumanB::~HumanB (){
}
