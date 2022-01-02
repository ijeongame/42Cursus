/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:16:44 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 19:59:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	private:
		std::string	type;
	public:
		Weapon(void);
		Weapon(std::string type);
		const	std::string &getType(void);
		void	setType(std::string type);
		~Weapon();
};

#endif
