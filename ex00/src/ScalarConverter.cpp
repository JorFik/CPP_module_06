/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:51:52 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 14:56:13 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void	ScalarConverter::convert(std::string const &str)
{
	UnitType		type;
	int				i;
	char			c;
	double			d;
	float			f;

	try{
		std::cout << "Input:\t\"" + str + '\"' << std::endl;
		type = _recognizeType(str);
		std::cout << "Type:\t" << type << std::endl << std::endl;
		switch (type)
		{
			case UnitType::CHAR:
				_cast_and_print(c = static_cast<char>(str[0]));
				break;
			case UnitType::INT:
				_cast_and_print(i = std::stoi(str));
				break;
			case UnitType::FLOAT:
				_cast_and_print(f = std::stof(str));
				break;
			case UnitType::DOUBLE:
				_cast_and_print(d = std::stod(str));
				break;
			default:
				throw ConverterException("Unknown type");
		}
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

std::ostream	&operator <<(std::ostream &os, UnitType const &type)
{
	switch (type)
	{
		case UnitType::CHAR:
			os << "CHAR";
			break;
		case UnitType::INT:
			os << "INT";
			break;
		case UnitType::FLOAT:
			os << "FLOAT";
			break;
		case UnitType::DOUBLE:
			os << "DOUBLE";
			break;
		default:
			os << "UNKNOWN";
			break;
	}
	return os;
}
