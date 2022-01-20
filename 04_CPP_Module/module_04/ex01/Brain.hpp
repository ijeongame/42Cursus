/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:05:49 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:00:27 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <cstdlib>

class Brain{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain &b);
		Brain& operator=(const Brain &b);
		~Brain(void);
		std::string const &getIdea(int index) const;
};

#endif
