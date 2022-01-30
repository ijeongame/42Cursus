/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:28:38 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/30 17:05:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	{
		std::cout << "================ mutant iterator test ================" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top : " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "size : " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "value : "<< *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "================ list test ================" << std::endl;
		std::list<int> list;

		list.push_back(5);
		list.push_back(17);

		std::cout << "top : " << list.back() << std::endl;

		list.pop_back();
		std::cout << "top : " << list.back() << std::endl;
		std::cout << "size : " << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator l_it = list.begin();

		for (; l_it != list.end(); l_it++)
		{
			std::cout << "value : " << *l_it << std::endl;
		}
		std::cout << "================ copy constructor test ================" << std::endl;
		MutantStack<int> s_copy(mstack);
		MutantStack<int> s_oper = mstack;

		s_copy.pop();
		s_copy.pop();
		s_copy.pop();
		s_copy.push(42);
		s_copy.push(43);
		s_copy.push(44);

		MutantStack<int>::iterator c_iter = s_copy.begin();
		for (; c_iter != s_copy.end(); c_iter++)
		{
			std::cout << *c_iter << std::endl;
		}

		std::cout << "-------------------------------------------------------" << std::endl;

		s_oper.pop();
		s_oper.pop();
		s_oper.pop();
		s_oper.push(52);
		s_oper.push(53);
		s_oper.push(54);

		MutantStack<int>::iterator o_iter = s_oper.begin();
		for (; o_iter != s_oper.end(); o_iter++)
		{
			std::cout << *o_iter << std::endl;
		}
	}
	{
		std::cout << "================ mutant reverse iterator test ================" << std::endl;
		MutantStack<char> mstack;
		mstack.push('a');
		mstack.push('b');
		mstack.push('c');
		mstack.push('d');
		mstack.push('e');
		MutantStack<char>::reverse_iterator rit = mstack.rbegin();
		MutantStack<char>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
}
