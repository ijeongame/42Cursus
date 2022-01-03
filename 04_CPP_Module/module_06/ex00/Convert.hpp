/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:46:27 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/03 17:43:43 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cmath>

class Convert
{
	private:
		const std::string	_input;
		bool	_e;
		Convert(void);
	public:
		Convert(const Convert& c);
		Convert(const std::string &input);
		~Convert(void);
		Convert& operator=(const Convert& c);

		const std::string& getInput(void) const;
		bool	getError(void) const;
		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double	toDouble(void) const;

		class ImpossibleException : public std::exception
		{
			const char *what() const throw()
			{
				return ("impossible");
			}
		};

		class NonDisplayableException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Non displayable");
			}
		};
};

std::ostream&	operator<<(std::ostream &o, Convert &c);

#endif
