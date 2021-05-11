/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** CommunicationError
*/

#include "CommunicationError.hpp"

CommunicationError::CommunicationError(const std::string &desc) noexcept : Error("Communication: " + desc)
{
}

CommunicationError::~CommunicationError()
{
}
