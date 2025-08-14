// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 14:53:21 by weast             #+#    #+#             //
//   Updated: 2025/08/14 16:52:52 by weast            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string input;
	Phonebook book;

	while (input != "EXIT")
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD" )
			book.add_contact();
		else if (input == "SEARCH")
			book.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
