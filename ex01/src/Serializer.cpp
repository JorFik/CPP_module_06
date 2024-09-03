/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:35:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 19:08:41 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(t_data *data)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(data);
	return (raw);
}

t_data	*Serializer::deserialize(uintptr_t raw)
{
	t_data	*data;

	data = reinterpret_cast<t_data *>(raw);
	return (data);
}
