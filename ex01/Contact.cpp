/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:02:44 by aisaev            #+#    #+#             */
/*   Updated: 2025/09/20 15:11:23 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

bool Contact::isEmpty() const {
	return firstName.empty();
}

void Contact::setFirstName(const std::string &fn)
{
	firstName = fn;
}
void Contact::setLastName(const std::string &ln)
{
	lastName = ln;
}
void Contact::setNickname(const std::string &nn)
{
	nickname = nn;
}
void Contact::setPhoneNumber(const std::string &pn)
{
	phoneNumber = pn;
}
void Contact::setDarkestSecret(const std::string &ds)
{
	darkestSecret = ds;
}

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
