/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:18:50 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 15:17:15 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private :
		std::string	name;
	public :
		Zombie();
		Zombie(std::string name);
		void announce();
		~Zombie();
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
