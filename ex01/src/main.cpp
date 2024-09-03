/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:32:58 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 19:43:28 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	t_data		data;
	uintptr_t	raw;
	t_data		*data_ptr;

	data.random_string_without_use = "Hello, World!";
	data.filling_string_without_use = "This is a filler string.";
	data.random_integer_to_have_variety = 42;

	raw = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(raw);

	std::cout << "Random string: " << data_ptr->random_string_without_use << std::endl;
	std::cout << "Filling string: " << data_ptr->filling_string_without_use << std::endl;
	std::cout << "Random integer: " << data_ptr->random_integer_to_have_variety << std::endl;

	return (0);
}
