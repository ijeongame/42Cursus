/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:40:18 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 21:05:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Karen();
		void complain(std::string level);
		~Karen();
};

#endif
