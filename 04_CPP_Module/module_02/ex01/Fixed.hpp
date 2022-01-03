/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:37:29 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/04 00:11:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
	private:
		int		value;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& f);
		Fixed(const int _int);
		Fixed(const float _float);
		Fixed&	operator=(const Fixed& f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &out, const Fixed &f);
#endif
