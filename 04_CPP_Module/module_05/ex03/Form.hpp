/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:08:00 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/20 15:46:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <string>
# include <fstream>

class Form
{
	private:
		const std::string	name;
		const std::string	target;
		const int			sign_grade;
		const int			exec_grade;
		bool				is_signed;
		Form(void);
	public:
		Form(const std::string &_name, const int &_sign_grade, const int &_exec_grade);
		Form(Form const &f);
		Form & operator=(Form const &f);
		~Form(void);

		std::string const & getName(void) const;
		bool getSign(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		void	beSigned(const Bureaucrat& bu);

		std::string const & getTarget(void) const;
		void	setTarget(std::string _target) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class NoSignedException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		void		executeCheck(Bureaucrat const &bu) const;
		virtual void execute(Bureaucrat const &bu) const = 0;
};

std::ostream&	operator<<(std::ostream& o, const Form &f);

#endif
