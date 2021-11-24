/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:02:54 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 16:59:41 by hkwon            ###   ########.fr       */
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
