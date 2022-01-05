/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:23:05 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/01 22:46:47 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& c);
		ClapTrap&	operator=(const ClapTrap& c);

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	const getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;

		void	setName(std::string _name);
		void	setHitPoints(unsigned int _hitPoints);
		void	setEnergyPoint(unsigned int _energyPoint);
		void	setAttackDamage(unsigned int _attackDamage);
};

#endif
