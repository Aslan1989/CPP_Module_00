/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:32 by aisaev            #+#    #+#             */
/*   Updated: 2025/09/20 14:45:23 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

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
