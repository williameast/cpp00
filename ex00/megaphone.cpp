// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 10:43:33 by weast             #+#    #+#             //
//   Updated: 2025/08/14 12:35:52 by weast            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char) std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
