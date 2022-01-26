/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:01:48 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 15:51:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);

	Form *makeForm(const std::string &name, const std::string & target);

	class NoNameFormException : public std::exception {
		public :
			const char* what() const throw()
			{
				return ("No Matching Type");
			};
	};
};

#endif
