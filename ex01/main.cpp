/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:06 by aisaev            #+#    #+#             */
/*   Updated: 2025/09/20 15:06:26 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

static std::string promptField(const std::string &field)
{
	std::string input;
	do
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
	}
	while (input.empty());
	return input;
}


static bool parseInt(const std::string& s, int& out) {
	std::istringstream iss(s);
	int x;
	char extra;
	if (!(iss >> x)) return false;
	if (iss >> extra) return false;
	out = x;
	return true;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			Contact c;
			c.setFirstName(promptField("First Name"));
			c.setLastName(promptField("Last Name"));
			c.setNickname(promptField("Nickname"));
			c.setPhoneNumber(promptField("Phone Number"));
			c.setDarkestSecret(promptField("Darkest Secret"));
			phoneBook.addContact(c);
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.getCount() == 0)
			{
				std::cout << "PhoneBook is empty!" << std::endl;
				continue;
			}
			phoneBook.displayContacts();
			std::cout << "Enter index: ";
			std::string idxStr;
			std::getline(std::cin, idxStr);
			if (!std::getline(std::cin, idxStr))
				break;
			int idx;
			if (parseInt(idxStr, idx))
			{
				phoneBook.displayContact(idx);
			}
			else
			{
				std::cout << "Invalid input!" << std::endl;
			}
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command!" << std::endl;
	}
	return 0;
}
