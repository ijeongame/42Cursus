/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:50:18 by hkwon            ###   ########.fr       */
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
