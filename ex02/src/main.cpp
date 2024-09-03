/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:54:26 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 20:04:32 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

static Base	*generate(void)
{
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "A instance created" << std::endl;
			return new A();
		case 1:
			std::cout << "B instance created" << std::endl;
			return new B();
		case 2:
			std::cout << "C instance created" << std::endl;
			return new C();
		default:
			return nullptr;
	}
}

static void	identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "It is a pointer to A" << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "It is a pointer to B" << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "It is a pointer to C" << std::endl;
}

static void	identify_from_reference(Base & p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "It is a referance to A" << std::endl;
	}
	catch (std::bad_cast & e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "It is a referance to B" << std::endl;
		}
		catch (std::bad_cast & e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "It is a referance to C" << std::endl;
			}
			catch (std::bad_cast & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
}

int	main(void)
{
	srand(time(nullptr));


	for (int i = 0; i < 10; i++)
	{
		std::cout << "\tTest " << i + 1 << std::endl;
		Base	*base = generate();

		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;
		std::cout << std::endl;
	}
	return (0);
}
