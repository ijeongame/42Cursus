/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:41 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 17:43:32 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 20:58:37 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

<<<<<<< HEAD
// 생성과 동시에 초기화를 시켜준다. 객체를 생성하기전에 초기화를 하는 부분.
HumanA::HumanA (std::string name, Weapon &weapon) : weapon(weapon){
=======
// 생성과 동시에 초기화를 시켜준다. 초기화 리스트 : 객체를 생성하기전에 초기화를 하는 부분.
HumanA::HumanA (std::string name, Weapon &weapon) : weapon(weapon){
	// 참조 변수의 경우 선언과 동시에
	// this->weapon = weapon;
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
	// 객체가 생성된 후에 변경
	this->name = name;
}

void HumanA::attack(){
<<<<<<< HEAD
	std::cout << name << "attacks with is" << weapon.getType() << std::endl;
=======
	std::cout << name << " attacks with is " << weapon.getType() << std::endl;
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
}

HumanA::~HumanA (){
}
