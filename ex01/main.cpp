/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:06 by aisaev            #+#    #+#             */
/*   Updated: 2025/11/03 20:30:52 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Ask the user to enter a value for a specific field.
 * 
 * The function displays the field name followed by a colon (": "),
 * reads a full line from standard input, and repeats until the user
 * enters a non-empty string.
 * 
 * @param field The name of the field to display as a prompt (for example, "First Name").
 * @return A non-empty string entered by the user.
 */
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


static bool parseInt(const std::string& s, int& out)
{
	std::istringstream iss(s);
	int x;
	char extra;
	if (!(iss >> x))
		return false;
	if (iss >> extra)
		return false;
	out = x;
	return true;
}

/**
 * @brief Check if a phone number is valid.
 *
 * The function makes sure that the phone number:
 * - is not empty
 * - may start with a '+' sign (only one)
 * - contains only digits (0–9)
 * - has between 5 and 15 digits in total
 *
 * @param normalized A string that should already contain only '+' and digits.
 * @return true if the phone number is valid, false otherwise.
 */
static bool isValidPhone(const std::string& normalized)
{
	std::string::size_type i = 0;
	const std::string::size_type digits = normalized.size();
	if (normalized.empty())
		return false;
	if (normalized[0] == '+')
	{
		if (normalized.size() == 1)
		return false;
		i = 1;
	}
	for (; i < normalized.size(); ++i)
	{
		if (!std::isdigit(normalized[i]))
			return false;
	}
	return digits >= 5 && digits <= 15;
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
			for (;;)
			{
				std::string raw = promptField("Phone Number");
				if (!raw.empty() && isValidPhone(raw)) {
					c.setPhoneNumber(raw);
					break;
				}
				std::cout << "Invalid phone. Use digits and optional leading '+'.\n";
			}
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
			if (!std::getline(std::cin, idxStr))
				break;
			int idx;
			if (parseInt(idxStr, idx))
				phoneBook.displayContact(idx);
			else
				std::cout << "Invalid input!" << std::endl;
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command!" << std::endl;
	}
	return 0;
}
