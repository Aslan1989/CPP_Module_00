/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:44 by aisaev            #+#    #+#             */
/*   Updated: 2025/11/10 17:47:42 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

bool Contact::isEmpty() const {
	return firstName.empty();
}

// ----- Setter implementations -----

void Contact::setFirstName(const std::string& fn)
{
	firstName = fn;
}
void Contact::setLastName(const std::string& ln)
{
	lastName = ln;
}
void Contact::setNickname(const std::string& nn)
{
	nickname = nn;
}
void Contact::setPhoneNumber(const std::string& pn)
{
	phoneNumber = pn;
}
void Contact::setDarkestSecret(const std::string& ds)
{
	darkestSecret = ds;
}

// ----- Getter implementations -----

std::string Contact::getFirstName() const
{
	return firstName;
}
std::string Contact::getLastName() const
{
	return lastName;
}
std::string Contact::getNickname() const
{
	return nickname;
}
std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
