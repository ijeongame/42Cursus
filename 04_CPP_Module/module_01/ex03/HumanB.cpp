/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:36:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 19:59:51 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name){
	this->name = name;
	weapon = NULL;
}

void HumanB::attack(){
	std::cout << name << " attacks with is " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

HumanB::~HumanB (){
}
