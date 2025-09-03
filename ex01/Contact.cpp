// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 12:39:46 by weast             #+#    #+#             //
//   Updated: 2025/08/20 15:28:01 by weast            ###   ########.fr       //
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
