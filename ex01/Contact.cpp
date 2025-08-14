// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 12:39:46 by weast             #+#    #+#             //
//   Updated: 2025/08/14 17:07:58 by weast            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>
#include "Contact.hpp"


// constructor
Contact::Contact() {}

// destructor
Contact::~Contact() {}

// getters
std::string Contact::get_name(void) const
{
	return(this->_first_name);
}

std::string Contact::get_surname(void) const
{
	return(this->_last_name);
}

std::string Contact::get_full_name() const
{
	return (this->_first_name + " (" + this->_nick_name + ") " + this->_last_name);
}

std::string Contact::get_nick(void) const
{
	return(this->_nick_name);
}

std::string Contact::get_number(void) const
{
	return(this->_phone_nr);
}

std::string Contact::get_secret(void) const
{
	return(this->_secret);
}


// setters
void	Contact::set_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_surname(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_nick(std::string str)
{
	this->_nick_name = str;
}

void	Contact::set_number(std::string str)
{
	this->_phone_nr = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}


static std::string get_input(const std::string &message)
{
    std::string input;

    while (true)
    {
        std::cout << message;
        std::getline(std::cin, input);
        if (!input.empty())
            return input;

        std::cout << "Field cannot be empty. Try again.\n";
    }
}

void Contact::capture_contact()
{
    set_name(get_input("First name: "));
    set_surname(get_input("Last name: "));
    set_nick(get_input("Nickname: "));
    set_number(get_input("Phone Number: "));
    set_secret(get_input("Secret: "));

    std::cout << get_full_name() + " added successfully.\n";
}

void Contact::print_contact()
{
	std::cout
		<< "FIRST : " << _first_name << std::endl
	    << "LAST  : " << _last_name  << std::endl
	    << "NICK  : " << _nick_name  << std::endl
		<< "TEL   : " << _phone_nr << std::endl
		<< "SECRET: " << _secret  << std::endl;
}
