/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:55 by aisaev            #+#    #+#             */
/*   Updated: 2025/11/10 17:46:24 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief The Contact class represents a single contact in the phone book.
 * It stores the first name, last name, nickname, phone number, and a secret.
 * All fields are private, to keep good encapsulation.
 */
class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	/**
	 * @brief Default constructor.
	 * Creates an empty contact. All fields are empty strings by default.
	 */
	Contact();
	/**
	 * @brief Check if the contact is empty.
	 * @return true if the first name is empty (used as a simple check).
	 */
	bool isEmpty() const;

	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickname(const std::string& nickname);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);

	// --- Getters (read data from the fields) ---
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
