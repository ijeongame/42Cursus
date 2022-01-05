/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:05:40 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/15 02:08:30 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	const std::string ideas[] = {
		"AB",
		"CD",
		"EF",
		"GH",
		"IJ",
	};
	std::cout << "Brain Constructor";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[rand() % (sizeof(ideas) / sizeof(std::string))];
	std::cout << std::endl;
}

Brain::Brain(const Brain &b)
{
	this->operator=(b);
	std::cout << "Brain Constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
	if (this != &b)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = b.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor" << std::endl;
}

std::string const &Brain::getIdea(int index) const
{
	return (ideas[index]);
}
