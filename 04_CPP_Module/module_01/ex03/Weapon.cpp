/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:21:37 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 16:48:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string type){
	this->type = type;
}

std::string &Weapon::getType(){
	return (type);
}

void Weapon::setType(std::string type){
	this->type = type;
}

Weapon::~Weapon(){
}
