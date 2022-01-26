/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:08:00 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 22:25:55 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

class Form
{
	private:
		const std::string	name;
		const int			sign_grade;
		const int			exec_grade;
		bool				is_signed;
		Form(void);
	public:
		Form(const std::string &_name, const int &_sign_grade, const int &_exec_grade);
		Form(Form const &f);
		Form & operator=(Form const &f);
		~Form(void);

		const std::string& getName(void) const;
		bool getSign(void) const;
		const int &getSignGrade(void) const;
		const int &getExecGrade(void) const;

		void	beSigned(const Bureaucrat& bu);

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
};

std::ostream&	operator<<(std::ostream& o, const Form &f);

#endif
