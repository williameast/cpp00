// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PhoneBook.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/14 12:37:32 by weast             #+#    #+#             //
//   Updated: 2025/08/14 17:36:26 by weast            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook
{
	private:
	Contact _contacts[8];
	int		_counter;
	int		_contact_count;

	// helpers
	std::string format_field(const std::string &str);
	Contact	capture_contact();
	void	print_contact(Contact contact);

	public:
	Phonebook();
	~Phonebook();

	void	add_contact();
	void	print_contacts();
	void	search();


};

#endif // PHONEBOOK_H
