/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:35:06 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/19 23:20:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materia[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & ms);
		MateriaSource &operator=(MateriaSource const & ms);
		virtual ~MateriaSource(void);

		void	learnMateria(AMateria* am);
		AMateria* createMateria(std::string const & type);

		AMateria const *getAMateria(int index) const;
};

#endif
