/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:32 by aisaev            #+#    #+#             */
/*   Updated: 2025/11/10 17:54:49 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/**
 * @brief The PhoneBook class manages up to 8 contacts.
 * When it becomes full, the oldest contact is overwritten.
 * Add a new contact to the phone book.
	* If there is free space, append it.
	* Otherwise, overwrite the oldest contact (circular buffer).
 * Display all details of a single contact by index.
 * Get the number of stored contacts.
 */
class PhoneBook
{
private:
	Contact contacts[8];
	int count;
	int oldest;
public:
	PhoneBook();
	void addContact(const Contact &newContact);
	void displayContacts() const;
	void displayContact(int index) const;
	int getCount() const;
};

#endif
