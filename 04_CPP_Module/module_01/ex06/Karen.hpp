/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:16:46 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 21:16:46 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   Updated: 2021/12/28 23:51:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <algorithm>
#include <string>

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
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
