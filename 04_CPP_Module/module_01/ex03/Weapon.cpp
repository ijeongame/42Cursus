/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:37 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 20:06:21 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){
}

Weapon::Weapon(std::string type){
	this->type = type;
}

const std::string &Weapon::getType(void){
	return (this->type);
}

void Weapon::setType(std::string type){
	this->type = type;
}

Weapon::~Weapon(){
}
