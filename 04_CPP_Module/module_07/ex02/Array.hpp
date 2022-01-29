/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:01:30 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/28 18:35:08 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_arr;
	public:
		Array(void)
		{
			_arr = new T[0];
			_size = 0;
		}
		Array(unsigned int n)
		{
			_arr = new T[n];
			_size = n;
		}
		Array(const Array &a)
		{
			_arr = new T[a.size()];
			_size = a.size();
			for (unsigned int i = 0; i < a.size(); i++)
				_arr[i] = a[i];
		}
		Array<T> operator=(const Array &a)
		{
			if (this != &a)
			{
				~Array();
				_size = a.size();
				_arr = new T[a.size()];
				for (unsigned int i = 0; i < a.size(); i++)
					_arr[i] = a[i];
			}
			return (*this);
		}
		const T &operator[](int i) const
		{
			if (i < 0 || i >= static_cast<int>(size()))
				throw Array::OutOfRangeArr();
			return (_arr[i]);
		}
		T &operator[](int i)
		{
			if (i < 0 || i >= static_cast<int>(size()))
				throw Array::OutOfRangeArr();
			return (_arr[i]);
		}
		~Array()
		{
			delete[] _arr;
			_arr = 0;
			_size = 0;
		}
		unsigned int size() const
		{
			return (_size);
		}
		class OutOfRangeArr : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Out Of Range");
			}
		};
};

#endif
