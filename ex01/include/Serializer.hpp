/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:27:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 18:55:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

typedef struct data
{
	std::string	random_string_without_use;
	std::string	filling_string_without_use;
	int			random_integer_to_have_variety;
}	t_data;

class Serializer
{
	public:
		Serializer()									= delete;
		Serializer(Serializer const &other)				= delete;
		~Serializer()									= delete;
		Serializer &operator=(Serializer const &other)	= delete;

		static uintptr_t	serialize(t_data *data);
		static t_data		*deserialize(uintptr_t raw);
};

#endif