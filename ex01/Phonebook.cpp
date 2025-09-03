// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Phonebook.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 15:36:55 by weast             #+#    #+#             //
//   Updated: 2025/08/14 17:41:10 by weast            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

// constructor
Phonebook::Phonebook() : _counter(0), _contact_count(0) {}
// destructor
Phonebook::~Phonebook() {}

// helpers

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

static bool is_valid(const std::string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '(' || c == ')')) {
            return false;
        }
    }
	return true;
}

static std::string get_numeric_input(const std::string &message)
{
    std::string input;

    while (true)
    {
        std::cout << message;
		if (!std::getline(std::cin, input))
			{
				std::cout << "\nInput cancelled (EOF).\n";
				return "";
			}
        if (!input.empty())
		{
			if (is_valid(input))
				return input;
			std::cout << "Phone number must consist of 0-9, + - (  ). Try again.\n";
		}
		if (input.empty())
			std::cout << "Field cannot be empty. Try again.\n";
    }
}

Contact Phonebook::capture_contact()
{
	Contact contact;
    contact.set_name(get_input("First name: "));
    contact.set_surname(get_input("Last name: "));
    contact.set_nick(get_input("Nickname: "));
    contact.set_number(get_numeric_input("Phone Number: "));
    contact.set_secret(get_input("Secret: "));

    std::cout << contact.get_full_name() + " added successfully.\n";
	return contact;
}

void Phonebook::print_contact(Contact contact)
{
	std::cout
		<< "FIRST : " << contact.get_name() << std::endl
	    << "LAST  : " << contact.get_surname()  << std::endl
	    << "NICK  : " << contact.get_nick()  << std::endl
		<< "TEL   : " << contact.get_number() << std::endl
		<< "SECRET: " << contact.get_secret() << std::endl;
}

// if string is longer than 10, replace remaining chars with ..
std::string Phonebook::format_field(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

// using a circular index, starts overwriting from beginning
void Phonebook::add_contact()
{
    if (_contact_count == 8)
        std::cout << "Phonebook full. Overwriting oldest contact.\n";

    _contacts[_counter] = capture_contact();

    _counter = (_counter + 1) % 8;
    if (_contact_count < 8)
        _contact_count++;
}

void	Phonebook::print_contacts()
{
	std::cout
		<< std::setw(10) << "Index: " << "|"
		<< std::setw(10) << "Name: " << "|"
		<< std::setw(10) << "Surname: " << "|"
		<< std::setw(10) << "Nickname: " << "|"
		<< std::endl;

	for (int i = 0; i < _contact_count; i++)
	{
		std::cout
			<< std::setw(10) << i + 1 << "|"
			<< std::setw(10) << format_field(_contacts[i].get_name()) << "|"
			<< std::setw(10) << format_field(_contacts[i].get_surname()) << "|"
			<< std::setw(10) << format_field(_contacts[i].get_nick()) << "|"
			<< std::endl;
	}
}

void	Phonebook::search()
{
	std::string input;

	if (Phonebook::_contact_count == 0)
	{
			std::cout << "Contact list is empty!\n";
			return;
	}

	print_contacts();

	std::cout << "Select contact index (1 to "
			  << Phonebook::_contact_count << ") ";
	std::getline(std::cin, input);

	if(input.size() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid input\n";
		return;
	}

	// convert input into integer, single digit.
	int index = (input[0] - '0') - 1;

	if (index < 0 || index >= _contact_count)
	{
			std::cout << "out of range\n";
			return ;
	}
	Phonebook::print_contact(_contacts[index]);
}
