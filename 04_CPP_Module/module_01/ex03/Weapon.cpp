/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:37 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 16:48:26 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 20:06:21 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

<<<<<<< HEAD
Weapon::Weapon(){
=======
Weapon::Weapon(void){
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
}

Weapon::Weapon(std::string type){
	this->type = type;
}

<<<<<<< HEAD
std::string &Weapon::getType(){
	return (type);
=======
const std::string &Weapon::getType(void){
	return (this->type);
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
}

void Weapon::setType(std::string type){
	this->type = type;
}

Weapon::~Weapon(){
}
