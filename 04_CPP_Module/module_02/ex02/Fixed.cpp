/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:22:46 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/30 23:08:37 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->value = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const int _int)
{
	this->value = _int << fractionalBits;
}

Fixed::Fixed(const float _float)
{
	this->value = roundf(_float * (1 << fractionalBits));
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> fractionalBits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &f)
{
	return (out << f.toFloat());
}

bool	Fixed::operator<(const Fixed& f)
{
	return (this->value < f.getRawBits());
}

bool	Fixed::operator>(const Fixed& f)
{
	return (this->value > f.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f)
{
	return (this->value >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed& f)
{
	return (this->value <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed& f)
{
	return (this->value == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f)
{
	return (this->value != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& f)
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& f)
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& f)
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& f)
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res = *this;

	this->value++;
	return (res);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res = *this;

	this->value--;
	return (res);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}
