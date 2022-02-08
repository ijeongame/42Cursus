/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:38:08 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/10 17:32:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		value = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const int _int)
{
	std::cout << "Int constructor called" << std::endl;
	value = _int << fractionalBits;
}

Fixed::Fixed(const float _float)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(_float * (1 << fractionalBits));
}

int	Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (1 << fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &f)
{
	return (out << f.toFloat());
}
