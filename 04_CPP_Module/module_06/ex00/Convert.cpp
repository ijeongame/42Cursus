/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:44:08 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 12:17:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

const std::string& Convert::getInput(void) const
{
	return (_input);
}

bool	Convert::getError(void) const
{
	return (_e);
}

//Convert
char	Convert::toChar(void) const
{
	int n;

	try
	{
		n = std::stoi(this->_input);
		if (n < 0 || n > 255)
		{
			throw Convert::ImpossibleException();
		}
	}
	catch (...)
	{
		throw Convert::ImpossibleException();
	}
	if (!std::isprint(n))
	{
		throw Convert::NonDisplayableException();
	}
	return (static_cast<char>(n));
}

int		Convert::toInt(void) const
{
	int	n;

	try
	{
		n = std::stoi(this->_input);
	}
	catch (...)
	{
		throw Convert::ImpossibleException();
	}
	return (n);
}

float	Convert::toFloat(void) const
{
	float n;

	try
	{
		n = std::stof(this->_input);
	}
	catch (...)
	{
		throw Convert::ImpossibleException();
	}
	return (n);
}

double	Convert::toDouble(void) const
{
	double n;

	try
	{
		n = std::stod(this->_input);
	}
	catch (...)
	{
		throw Convert::ImpossibleException();
	}
	return (n);
}

//PrintConvert
static void	printChar(std::ostream &o, Convert &c)
{
	o << "char : ";
	try
	{
		char ch = c.toChar();
		std::cout << "'" << ch << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void	printInt(std::ostream &o, Convert &c)
{
	o << "int : ";
	try
	{
		std::cout << c.toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void	printFloat(std::ostream &o, Convert &c)
{
	o << "float: ";
	try
	{
		float f = c.toFloat();

		if (std::isnan(f) && std::signbit(f))
			o << "-";
		o << f;
		if (!std::isnan(f) && f - (int)f == 0)
			o << ".0";
		o << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		o << e.what() << std::endl;
	}
}

static void	printDouble(std::ostream &o, Convert &c)
{
	o << "Double: ";
	try
	{
		double d = c.toDouble();

		if (std::isnan(d) && std::signbit(d))
			o << "-";
		o << d;
		if (!std::isnan(d) && d - (int)d == 0)
			o << ".0";
		o << std::endl;
	}
	catch (const std::exception &e)
	{
		o << e.what() << std::endl;
	}
}

static int	printCheck(std::string _input)
{
	int	i = 0;
	int	f = 0;
	int	error = 0;
	if (_input.compare("inf") == 0			\
		|| _input.compare("+inf") == 0		\
		|| _input.compare("-inf") == 0		\
		|| _input.compare("nan") == 0)
		f = 1;
	if (_input.compare("inff") == 0			\
		|| _input.compare("+inff") == 0		\
		|| _input.compare("-inff") == 0		\
		|| _input.compare("nanf") == 0)
		f = 1;
	if (!f && _input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0]))
		error = 1;
	if (!f)
	{
		while (_input[++i])
		{
			if (std::isalpha(_input[i]) && _input[i] != 'f')
			{
				error = 1;
				break ;
			}
			if (_input[i] == 'f')
			{
				if (std::isprint(_input[i + 1]))
				{
					error = 1;
					break ;
				}
			}
			if (_input[i] == '.')
			{
				if (std::isprint(_input[i + 1]) && _input[i + 1] != 'f')
				{
					error = 1;
					break ;
				}
			}
		}
	}
	return (error);
}

std::ostream&	operator<<(std::ostream &o, Convert &c)
{
	if (c.getError())
	{
		o << "Argment Invaild" << std::endl;
		return (o);
	}
	printChar(o, c);
	printInt(o, c);
	printFloat(o, c);
	printDouble(o, c);
	return (o);
}

Convert::Convert(void) : _input(""), _e(false)
{
}

Convert::Convert(const std::string &input): _input(input), _e(false)
{
	try
	{
		if (printCheck(_input))
			throw true;
	}
	catch(...)
	{
		_e = true;
	}
}

Convert::Convert(const Convert& c)
{
	*this = c;
}

Convert::~Convert(void) {}

Convert& Convert::operator=(const Convert& c)
{
	if (this != &c)
		return (*this);
	return (*this);
}
