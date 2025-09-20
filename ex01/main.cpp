/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:06 by aisaev            #+#    #+#             */
/*   Updated: 2025/09/20 15:35:39 by aisaev           ###   ########.fr       */
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


static std::string normalizePhone(const std::string& s) {
	std::string out;
	out.reserve(s.size());
	for (std::string::size_type i = 0; i < s.size(); ++i) {
		unsigned char ch = static_cast<unsigned char>(s[i]);
		if (std::isdigit(ch)) {
			out.push_back(static_cast<char>(ch));
		} else if (s[i] == '+' && out.empty()) {
			out.push_back('+');
		} else if (s[i] == ' ' || s[i] == '-' || s[i] == '(' || s[i] == ')') {
		} else {
			return std::string();
		}
	}
	return out;
}

static bool isValidPhone(const std::string& normalized) {
	if (normalized.empty())
		return false;
	std::string::size_type i = 0;
	if (normalized[0] == '+') {
		if (normalized.size() == 1) return false;
		i = 1;
	}
	for (; i < normalized.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(normalized[i])))
			return false;
	}

	const std::string::size_type digits =
		normalized.size() - (normalized[0] == '+' ? 1 : 0);
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
				std::string norm = normalizePhone(raw);
				if (!norm.empty() && isValidPhone(norm)) {
					c.setPhoneNumber(norm);
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
