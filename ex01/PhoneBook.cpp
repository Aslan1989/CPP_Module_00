/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:18 by aisaev            #+#    #+#             */
/*   Updated: 2025/11/10 18:25:06 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Constructor: sets count and oldest to zero (empty phone book).
 */
PhoneBook::PhoneBook() : count(0), oldest(0) {}

/**
 * @brief Add a contact. If there is still space (less than 8),
 * the contact is added at the end. Otherwise, overwrite the oldest one.
 * go to the next slot in a circle
 */
void PhoneBook::addContact(const Contact &newContact)
{
	if (count < 8)
	{
		contacts[count] = newContact;
		count++;
	}
	else
	{
		contacts[oldest] = newContact;
		oldest = (oldest + 1) % 8;
	}
}

static std::string formatField(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void PhoneBook::displayContacts() const
{
	int	i = 0;
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	while (i < count)
	{
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
		i++;		  
	}
}

/**
 * @brief Display one contact in detail by its index (1-based).
 * If the index is invalid, print an error message.
 * convert from 1-based to 0-based
 */
void PhoneBook::displayContact(int index) const
{
	index -= 1;
	if (index < 0 || index >= count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
int PhoneBook::getCount() const
{
	return count;
}
