/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:36:39 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/29 23:48:47 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Span
{
	private:
		std::vector<int> _vec;
		Span(void);
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span& s);
		Span& operator=(const Span& s);

		void addNumber(int value);
		void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);

		int shortestSpan(void);
		int longestSpan(void);

		const std::vector<int>& getData(void) const;
		class StoreException : public std::exception
		{
			public:
				const char* what() const throw(){
					return ("Cannot Store");
				}
		};
		class FindException : public std::exception
		{
			public:
				const char* what() const throw(){
					return ("Cannot Find");
				}
		};

};
#endif
