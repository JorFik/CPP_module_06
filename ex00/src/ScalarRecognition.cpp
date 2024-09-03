/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarRecognition.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:48 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 13:41:55 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static UnitType	is_int(std::string const &str)
{
	size_t		i = 0;
	UnitType	is_int = UnitType::UNKNOWN;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < str.length())
	{
		if (str[i] == '.' || str[i] == 'f')
			return UnitType::FLOAT;
		if (!std::isdigit(str[i]))
			return UnitType::UNKNOWN;
		i++;
		is_int = UnitType::INT;
	}
	return is_int;
}

static UnitType	is_float_or_double(std::string const &str)
{
	size_t		i = str.find('.');
	std::string	substr;
	bool		dot_found = false;

	if (i == std::string::npos || i > str.find('f'))
		i = str.find('f');
	if (i == std::string::npos)
		return UnitType::UNKNOWN;
	substr = str.substr(i);
	i = -1;
	while (++i < substr.length())
	{
		if (substr[i] == '.')
		{
			if (dot_found)
				return UnitType::UNKNOWN;
			dot_found = true;
			continue ;
		}
		if (substr[i] == 'f' && i == substr.length() - 1)
			return UnitType::FLOAT;
		if (!std::isdigit(substr[i]))
			return UnitType::UNKNOWN;
	}
	return UnitType::DOUBLE;
}

static UnitType	is_num_type(std::string const &str)
{
	UnitType	result = UnitType::UNKNOWN;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return UnitType::DOUBLE;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return UnitType::FLOAT;
	if ((result = is_int(str)) == UnitType::INT)
		return UnitType::INT;
	if (result == UnitType::FLOAT)
		result = is_float_or_double(str);
	switch (result){
		case UnitType::FLOAT:
			return UnitType::FLOAT;
		case UnitType::DOUBLE:
			return UnitType::DOUBLE;
		default:
			return UnitType::UNKNOWN;
	}
}

UnitType	ScalarConverter::_recognizeType(std::string const &str)
{
	if (str.empty())
		throw ConverterException("Empty string");
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (UnitType::CHAR);
	return (is_num_type(str));
}
