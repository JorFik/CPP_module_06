/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarCasting.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:40:33 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 14:58:16 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <type_traits>

void	ScalarConverter::_print_casted_values(char c, int i, float f, double d)
{
	std::cout << "char:\t";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int:\t" << i << std::endl;
	if (f - static_cast<int>(f) == 0)
		std::cout << "float:\t" << f << ".0f" << std::endl;
	else
		std::cout << "float:\t" << f << "f" << std::endl;
	if (d - static_cast<int>(d) == 0)
		std::cout << "double:\t" << d << ".0" << std::endl;
	else
		std::cout << "double:\t" << d << std::endl;
}

static	void	print_casted_values(float f, double d)
{
	std::cout << "char:\timpossible" << std::endl;
	std::cout << "int:\timpossible" << std::endl;
	if ((d < std::numeric_limits<float>::min()
		|| d > std::numeric_limits<float>::max())
		&& !std::isinf(d))
		std::cout << "float:\timpossible" << std::endl;
	else if (f - static_cast<int>(f) == 0)
		std::cout << "float:\t" << f << ".0f" << std::endl;
	else
		std::cout << "float:\t" << f << "f" << std::endl;
	if (d - static_cast<int>(d) == 0)
		std::cout << "double:\t" << d << ".0" << std::endl;
	else
		std::cout << "double:\t" << d << std::endl;
}

int	ScalarConverter::_safe_cast(const float &value, double &d, char &c, int &i)
{
	if (std::isinf(value) || std::isnan(value)
		|| value > std::numeric_limits<int>::max())
		return (print_casted_values(value, d), 1);
	c = static_cast<char>(value);
	i = static_cast<int>(value);
	return (0);
}

int	ScalarConverter::_safe_cast(const double &value, float &f, char &c, int &i)
{
	if (std::isinf(value) || std::isnan(value)
		|| value > std::numeric_limits<int>::max())
		return (print_casted_values(f, value), 1);
	c = static_cast<char>(value);
	i = static_cast<int>(value);
	return (0);
}
