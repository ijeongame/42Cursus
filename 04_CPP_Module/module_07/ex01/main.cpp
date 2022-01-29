/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:13:01 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/28 21:32:48 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// int main(void)
// {
// 	char a[5] = {'a', 'b', 'c', 'd', 'e'};
// 	int b[6] = {1, 2, 3, 4, 5, 6};
// 	double c[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	std::string d[4] = {"hkwon", "seoul", "busan", "42"};

// 	std::cout << "Test iter type <char>" << std::endl;
// 	iter(a, sizeof(a)/sizeof(*a), print);
// 	std::cout << std::endl;

// 	std::cout << "Test iter type <int>" << std::endl;
// 	iter(b, sizeof(b)/sizeof(*b), print);
// 	std::cout << std::endl;
// 	iter(b, sizeof(b)/sizeof(*b), printAdd);
// 	iter(b, sizeof(b)/sizeof(*b), print);
// 	std::cout << std::endl;

// 	std::cout << "Test iter type <double>" << std::endl;
// 	iter(c, sizeof(c)/sizeof(*c), print);
// 	std::cout << std::endl;
// 	iter(c, sizeof(c)/sizeof(*c), printAdd);
// 	iter(c, sizeof(c)/sizeof(*c), print);
// 	std::cout << std::endl;

// 	std::cout << "Test iter type <std::string>" << std::endl;
// 	iter(d, sizeof(d)/sizeof(*d), print);
// }

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
