/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:16:44 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 16:47:54 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 19:59:04 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400

class Weapon{
	private:
		std::string	type;
	public:
<<<<<<< HEAD
		Weapon();
		Weapon(std::string type);
		std::string &getType();
=======
		Weapon(void);
		Weapon(std::string type);
		const	std::string &getType(void);
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
		void	setType(std::string type);
		~Weapon();
};

#endif
