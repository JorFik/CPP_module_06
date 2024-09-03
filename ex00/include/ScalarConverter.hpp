/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:26:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 13:46:57 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits>

enum class UnitType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

std::ostream	&operator <<(std::ostream &os, UnitType const &type);

class ScalarConverter
{
	private:
		static UnitType	_recognizeType(std::string const &str);
		static void	_print_casted_values(char c, int i, float f, double d);
		static int	_safe_cast(const float &value, double &d, char &c, int &i);
		static int	_safe_cast(const double &value, float &f, char &c, int &i);

		template <typename T> static void	_cast_and_print(T &value);

	public:
		static void	convert(std::string const &str);

		class ConverterException;
};

template <typename T>
void	ScalarConverter::_cast_and_print(T &value)
{
	char	c;
	int		i;
	float	f;
	double	d;

	f = static_cast<float>(value);
	d = static_cast<double>(value);
	if (std::is_same_v<T, float>)
	{
		if (_safe_cast(f, d, c, i))
			return ;
	}
	if (std::is_same_v<T, double>)
	{
		if (_safe_cast(d, f, c, i))
			return ;
	}
	c = static_cast<char>(value);
	i = static_cast<int>(value);
	_print_casted_values(c, i, f, d);
}


typedef class ScalarConverter::ConverterException : public std::exception
{
	private:
		std::string		_error_type;
	public:
		ConverterException()					=	delete;
		~ConverterException() noexcept override	=	default;
		ConverterException(std::string const &error_type);
		virtual const char*	what() const noexcept override;
}	t_ConverterException;

#endif