/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:23:05 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/15 19:44:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string _name);
		virtual ~ClapTrap(void);
		ClapTrap(const ClapTrap& c);
		ClapTrap&	operator=(const ClapTrap& c);

		virtual void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;

		void	setName(std::string _name);
		void	setHitPoints(unsigned int _hitPoints);
		void	setEnergyPoint(unsigned int _energyPoint);
		void	setAttackDamage(unsigned int _attackDamage);
};

#endif
