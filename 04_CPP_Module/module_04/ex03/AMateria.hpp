/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:57:20 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 23:43:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string		type;
	public:
		AMateria(void);
		AMateria(std::string const &_type);
		AMateria(AMateria const &am);
		AMateria & operator=(AMateria const &am);
		virtual ~AMateria(void);

		std::string const &getType() const; //Returns the materia type
		// unsigned int	getXp() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
