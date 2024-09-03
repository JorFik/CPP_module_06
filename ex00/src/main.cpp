/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:31:13 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 13:48:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

#ifdef TEST
void	try_invalid_casting(void)
{
	ScalarConverter::convert("");
	std::cout << std::endl;

	ScalarConverter::convert(" ");
	std::cout << std::endl;

	ScalarConverter::convert("42.0.0");
	std::cout << std::endl;

	ScalarConverter::convert("42.0f.0");
	std::cout << std::endl;

	ScalarConverter::convert("42.0f0");
	std::cout << std::endl;

	ScalarConverter::convert("42..0");
	std::cout << std::endl;

	ScalarConverter::convert("Hello World");
	std::cout << std::endl;

	ScalarConverter::convert("42f.");
	std::cout << std::endl;
}

int		main(void)
{
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.42");
	std::cout << std::endl;
	ScalarConverter::convert("42.123123123f");
	std::cout << std::endl;
	ScalarConverter::convert("42.f");
	std::cout << std::endl;
	ScalarConverter::convert("42.");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max()) + 'f');
	std::cout << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::min()) + 'f');
	std::cout << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::max()));
	std::cout << std::endl;
	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::min()));
	std::cout << std::endl;
	try_invalid_casting();
	return 0;
}
#else

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

#endif