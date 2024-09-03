/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterExceptions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:02:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 16:50:23 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

t_ConverterException::ConverterException(std::string const &error_type):
	_error_type(error_type)
{}

const char*	t_ConverterException::what() const noexcept
{
	static std::string		error_message;

	error_message = "An error occured during the conversion: " + _error_type;
	return error_message.c_str();
}
