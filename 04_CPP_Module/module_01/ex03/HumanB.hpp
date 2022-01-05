/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:42:53 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:50:03 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		Weapon		*weapon;
		std::string name;
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &weapon);
		~HumanB();
};

#endif
