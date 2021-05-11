/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** PizzaError
*/

#include "PizzaError.hpp"

PizzaError::PizzaError(const std::string &type, const std::string &desc) noexcept
    : ParseError("invalid pizza " + type + ": \"" + desc + "\"")
{
}