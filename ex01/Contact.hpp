// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   contact.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 14:31:01 by weast             #+#    #+#             //
//   Updated: 2025/08/14 16:37:00 by weast            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_nr;
	std::string _secret;

	public:
	// constructor
	Contact();
	// destructor uses ~ tilde
	~Contact();

	// getters;

	std::string get_name(void) const;
	std::string get_surname(void) const;
	std::string get_full_name(void) const;
	std::string get_nick(void) const;
	std::string get_number(void) const;
	std::string get_secret(void) const;

	// setters;

	void	set_name(std::string str);
	void	set_surname(std::string str);
	void	set_nick(std::string str);
	void	set_number(std::string str);
	void	set_secret(std::string str);

	// io
	// void	capture_contact();
	// void	print_contact();
};



#endif // CONTACT_HPP
