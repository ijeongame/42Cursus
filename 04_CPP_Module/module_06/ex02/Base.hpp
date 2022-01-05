/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:16:27 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 19:58:37 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <exception>
# include <iostream>
# include <string>

class Base{
	private:
	public:
		virtual ~Base(void){};
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
