/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:23:35 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 22:25:59 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

# define HIGHEST	1
# define LOWEST		150

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
		Bureaucrat(void);
	public:
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat(Bureaucrat const &bu);
		Bureaucrat & operator=(Bureaucrat const &bu);
		~Bureaucrat(void);

		std::string const & getName(void) const;
		int getGrade(void) const;
		void increaseGrade(void);
		void decreaseGrade(void);

		void	signForm(Form & f);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw()
				{
					return ("Grade Too High");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw()
				{
					return ("Grade Too Low");
				}
		};

		void executeForm(Form const & f);
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bu);

#endif
