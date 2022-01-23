/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:20:50 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/22 17:26:06 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "Constructor MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & ms)
{
	const AMateria*	temp;

	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
		{
			delete materia[i];
			materia[i] = NULL;
		}
		temp = ms.getAMateria(i);
		if (temp)
			this->materia[i] = temp->clone();
	}
	std::cout << "Copy Constructor MateriaSource" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const & ms)
{
	const AMateria*	temp;

	if (this != &ms)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materia[i])
			{
				delete materia[i];
				materia[i] = NULL;
			}
			temp = ms.getAMateria(i);
			if (temp)
				this->materia[i] = temp->clone();
		}
		std::cout << "Copy Constructor MateriaSource" << std::endl;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
		{
			delete materia[i];
			materia[i] = NULL;
		}
	}
	std::cout << "Destructor MateriaSource" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* am)
{
	if (!am)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!materia[i])
		{
			materia[i] = am;
			std::cout << "i : " << i << " learnMateria of : " << am->getType() << std::endl;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
		{
			std::cout << "i : " << i << " CreateMateria of : " << type << std::endl;
			return (materia[i]->clone());
		}
	}
	std::cout << "createMateria failed of : " << type << std::endl;
	return (NULL);
}

AMateria const *MateriaSource::getAMateria(int index) const
{
	return (this->materia[index]);
}
