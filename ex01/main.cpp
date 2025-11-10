/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:06 by aisaev            #+#    #+#             */
/*   Updated: 2025/11/10 18:22:01 by aslan            ###   ########.fr       */
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
	if (!(iss >> x))
		return false;
	out = x;
	return true;
}

/**
 * @brief Main function of the PhoneBook program.
 *
 * This function controls the main menu loop.
 * It waits for the user to type a command:
 *  - ADD    → create a new contact
 *  - SEARCH → show and select a contact
 *  - EXIT   → quit the program
 *
 * The program keeps running until the user types EXIT
 * or sends an end-of-file signal (Ctrl+D).
 *
 * @return 0 when the program ends successfully.
 */
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
				if (!raw.empty()) {
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
