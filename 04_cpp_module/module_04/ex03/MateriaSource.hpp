/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:35:06 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/23 15:57:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
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
